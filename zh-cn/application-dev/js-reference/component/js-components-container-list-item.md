# list-item<a name="ZH-CN_TOPIC_0000001209412123"></a>

-   [权限列表](#zh-cn_topic_0000001127125046_section11257113618419)
-   [子组件](#zh-cn_topic_0000001127125046_section9288143101012)
-   [属性](#zh-cn_topic_0000001127125046_section2907183951110)
-   [样式](#zh-cn_topic_0000001127125046_section5775351116)
-   [事件](#zh-cn_topic_0000001127125046_section1948820711216)
-   [方法](#zh-cn_topic_0000001127125046_section2279124532420)
-   [示例](#zh-cn_topic_0000001127125046_section634316188515)

<[list](js-components-container-list.md#ZH-CN_TOPIC_0000001163932194)\>的子组件，用来展示列表具体item。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>由于父元素list组件的align-items默认样式为stretch，该组件宽度默认充满list组件。设置父元素list组件的align-items样式为非stretch来生效自定义宽度。

## 权限列表<a name="zh-cn_topic_0000001127125046_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001127125046_section9288143101012"></a>

支持。

## 属性<a name="zh-cn_topic_0000001127125046_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001127125046_table1868413436126"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125046_row7684164319127"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.479999999999999%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.08%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125046_p3684134381211"><a name="zh-cn_topic_0000001127125046_p3684134381211"></a><a name="zh-cn_topic_0000001127125046_p3684134381211"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.56%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="zh-cn_topic_0000001127125046_zh-cn_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125046_row14827156171315"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125046_p2095581381314"><a name="zh-cn_topic_0000001127125046_p2095581381314"></a><a name="zh-cn_topic_0000001127125046_p2095581381314"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125046_p1956151315137"><a name="zh-cn_topic_0000001127125046_p1956151315137"></a><a name="zh-cn_topic_0000001127125046_p1956151315137"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125046_p8956111351319"><a name="zh-cn_topic_0000001127125046_p8956111351319"></a><a name="zh-cn_topic_0000001127125046_p8956111351319"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125046_p14956141314133"><a name="zh-cn_topic_0000001127125046_p14956141314133"></a><a name="zh-cn_topic_0000001127125046_p14956141314133"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.56%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125046_p1595671312135"><a name="zh-cn_topic_0000001127125046_p1595671312135"></a><a name="zh-cn_topic_0000001127125046_p1595671312135"></a>list-item类型，默认值为default，同一list中可以包含多种type的list-item，相同type的list-item需要确保渲染后的视图布局也相同，如果type固定，则使用show属性代替if属性，确保视图布局不变。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125046_row182818671318"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125046_p209561313171315"><a name="zh-cn_topic_0000001127125046_p209561313171315"></a><a name="zh-cn_topic_0000001127125046_p209561313171315"></a>primary</p>
</td>
<td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125046_p195631313131"><a name="zh-cn_topic_0000001127125046_p195631313131"></a><a name="zh-cn_topic_0000001127125046_p195631313131"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125046_p7956181316134"><a name="zh-cn_topic_0000001127125046_p7956181316134"></a><a name="zh-cn_topic_0000001127125046_p7956181316134"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125046_p1895681321315"><a name="zh-cn_topic_0000001127125046_p1895681321315"></a><a name="zh-cn_topic_0000001127125046_p1895681321315"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.56%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125046_p995671314134"><a name="zh-cn_topic_0000001127125046_p995671314134"></a><a name="zh-cn_topic_0000001127125046_p995671314134"></a>设置为true表示该item是group中的主item，即收拢时显示的item。如果有多个primary，以第一个为准。如果没有标记为primary的item，则以第一个item为主item。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125046_row16295321132"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125046_p16956101311310"><a name="zh-cn_topic_0000001127125046_p16956101311310"></a><a name="zh-cn_topic_0000001127125046_p16956101311310"></a>section</p>
</td>
<td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125046_p195611135133"><a name="zh-cn_topic_0000001127125046_p195611135133"></a><a name="zh-cn_topic_0000001127125046_p195611135133"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125046_p209561413191315"><a name="zh-cn_topic_0000001127125046_p209561413191315"></a><a name="zh-cn_topic_0000001127125046_p209561413191315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125046_p20956111318130"><a name="zh-cn_topic_0000001127125046_p20956111318130"></a><a name="zh-cn_topic_0000001127125046_p20956111318130"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.56%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125046_p2956161391313"><a name="zh-cn_topic_0000001127125046_p2956161391313"></a><a name="zh-cn_topic_0000001127125046_p2956161391313"></a>当前item的匹配字符串，如不设置则为空。不支持动态修改。group内只有主item设置有效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125046_row1629515214134"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125046_p2095641311138"><a name="zh-cn_topic_0000001127125046_p2095641311138"></a><a name="zh-cn_topic_0000001127125046_p2095641311138"></a>sticky</p>
</td>
<td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125046_p6957141317138"><a name="zh-cn_topic_0000001127125046_p6957141317138"></a><a name="zh-cn_topic_0000001127125046_p6957141317138"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125046_p295771313131"><a name="zh-cn_topic_0000001127125046_p295771313131"></a><a name="zh-cn_topic_0000001127125046_p295771313131"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125046_p199571613151311"><a name="zh-cn_topic_0000001127125046_p199571613151311"></a><a name="zh-cn_topic_0000001127125046_p199571613151311"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.56%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125046_p29571313131310"><a name="zh-cn_topic_0000001127125046_p29571313131310"></a><a name="zh-cn_topic_0000001127125046_p29571313131310"></a>设置当前item是否为吸顶item以及其吸顶消失的效果，当前仅支持纵向list，group内部的item不可吸顶，设置该属性无效。</p>
<a name="zh-cn_topic_0000001127125046_ul69572137130"></a><a name="zh-cn_topic_0000001127125046_ul69572137130"></a><ul id="zh-cn_topic_0000001127125046_ul69572137130"><li>none：当前item不吸顶。</li><li>normal：当前item吸顶，消失效果滑动消失。</li><li>opacity：当前item吸顶，消失效果渐隐消失，仅在智能穿戴上支持。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125046_row4396145720125"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125046_p195701331315"><a name="zh-cn_topic_0000001127125046_p195701331315"></a><a name="zh-cn_topic_0000001127125046_p195701331315"></a>stickyradius</p>
</td>
<td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125046_p2095751320137"><a name="zh-cn_topic_0000001127125046_p2095751320137"></a><a name="zh-cn_topic_0000001127125046_p2095751320137"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125046_p795718138135"><a name="zh-cn_topic_0000001127125046_p795718138135"></a><a name="zh-cn_topic_0000001127125046_p795718138135"></a>1000px</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125046_p1495781391311"><a name="zh-cn_topic_0000001127125046_p1495781391311"></a><a name="zh-cn_topic_0000001127125046_p1495781391311"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.56%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125046_p1295771341313"><a name="zh-cn_topic_0000001127125046_p1295771341313"></a><a name="zh-cn_topic_0000001127125046_p1295771341313"></a>设置智能穿戴上吸顶item的圆弧效果半径，未设置时使用默认半径。sticky属性为none时，设置该属性无效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125046_row6359185421211"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125046_p109577139132"><a name="zh-cn_topic_0000001127125046_p109577139132"></a><a name="zh-cn_topic_0000001127125046_p109577139132"></a>clickeffect<sup id="zh-cn_topic_0000001127125046_sup1375415364114"><a name="zh-cn_topic_0000001127125046_sup1375415364114"></a><a name="zh-cn_topic_0000001127125046_sup1375415364114"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125046_p9957161341310"><a name="zh-cn_topic_0000001127125046_p9957161341310"></a><a name="zh-cn_topic_0000001127125046_p9957161341310"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125046_p99571013181316"><a name="zh-cn_topic_0000001127125046_p99571013181316"></a><a name="zh-cn_topic_0000001127125046_p99571013181316"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125046_p139571513121313"><a name="zh-cn_topic_0000001127125046_p139571513121313"></a><a name="zh-cn_topic_0000001127125046_p139571513121313"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.56%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125046_p99581613141313"><a name="zh-cn_topic_0000001127125046_p99581613141313"></a><a name="zh-cn_topic_0000001127125046_p99581613141313"></a>设置当前item是否有点击动效。</p>
<a name="zh-cn_topic_0000001127125046_ul1958513101318"></a><a name="zh-cn_topic_0000001127125046_ul1958513101318"></a><ul id="zh-cn_topic_0000001127125046_ul1958513101318"><li>false：item点击时无点击动效。</li><li>true：item点击时有点击动效。</li></ul>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001127125046_section5775351116"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001127125046_table164819331216"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125046_row1548217331922"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125046_p19482733426"><a name="zh-cn_topic_0000001127125046_p19482733426"></a><a name="zh-cn_topic_0000001127125046_p19482733426"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125046_p174821332212"><a name="zh-cn_topic_0000001127125046_p174821332212"></a><a name="zh-cn_topic_0000001127125046_p174821332212"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125046_p1948203319214"><a name="zh-cn_topic_0000001127125046_p1948203319214"></a><a name="zh-cn_topic_0000001127125046_p1948203319214"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125046_p1482733627"><a name="zh-cn_topic_0000001127125046_p1482733627"></a><a name="zh-cn_topic_0000001127125046_p1482733627"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125046_p1348213331227"><a name="zh-cn_topic_0000001127125046_p1348213331227"></a><a name="zh-cn_topic_0000001127125046_p1348213331227"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125046_row124821733120"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125046_p34821331428"><a name="zh-cn_topic_0000001127125046_p34821331428"></a><a name="zh-cn_topic_0000001127125046_p34821331428"></a>column-span</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125046_p24823331213"><a name="zh-cn_topic_0000001127125046_p24823331213"></a><a name="zh-cn_topic_0000001127125046_p24823331213"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125046_p1848211334211"><a name="zh-cn_topic_0000001127125046_p1848211334211"></a><a name="zh-cn_topic_0000001127125046_p1848211334211"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125046_p14482133318219"><a name="zh-cn_topic_0000001127125046_p14482133318219"></a><a name="zh-cn_topic_0000001127125046_p14482133318219"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125046_p24821933921"><a name="zh-cn_topic_0000001127125046_p24821933921"></a><a name="zh-cn_topic_0000001127125046_p24821933921"></a>当前的list-item需要在list中占据的列的数量，默认占一列，仅在list为多列时生效。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001127125046_section1948820711216"></a>

除支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)外，还支持如下事件：

<a name="zh-cn_topic_0000001127125046_table7489127521"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125046_row848957922"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125046_p748914712220"><a name="zh-cn_topic_0000001127125046_p748914712220"></a><a name="zh-cn_topic_0000001127125046_p748914712220"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.82228222822282%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125046_p194899713219"><a name="zh-cn_topic_0000001127125046_p194899713219"></a><a name="zh-cn_topic_0000001127125046_p194899713219"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52.32523252325233%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125046_p14489471229"><a name="zh-cn_topic_0000001127125046_p14489471229"></a><a name="zh-cn_topic_0000001127125046_p14489471229"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125046_row14891075219"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125046_p124898715214"><a name="zh-cn_topic_0000001127125046_p124898715214"></a><a name="zh-cn_topic_0000001127125046_p124898715214"></a>sticky</p>
</td>
<td class="cellrowborder" valign="top" width="22.82228222822282%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125046_p048977429"><a name="zh-cn_topic_0000001127125046_p048977429"></a><a name="zh-cn_topic_0000001127125046_p048977429"></a>{ state: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="52.32523252325233%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125046_p3489773215"><a name="zh-cn_topic_0000001127125046_p3489773215"></a><a name="zh-cn_topic_0000001127125046_p3489773215"></a>吸顶组件回调事件。</p>
<p id="zh-cn_topic_0000001127125046_p44891171220"><a name="zh-cn_topic_0000001127125046_p44891171220"></a><a name="zh-cn_topic_0000001127125046_p44891171220"></a>value: false表示当前item处于非吸顶状态；</p>
<p id="zh-cn_topic_0000001127125046_p74892071427"><a name="zh-cn_topic_0000001127125046_p74892071427"></a><a name="zh-cn_topic_0000001127125046_p74892071427"></a>value: true表示当前item处于吸顶状态；</p>
<p id="zh-cn_topic_0000001127125046_p74895716210"><a name="zh-cn_topic_0000001127125046_p74895716210"></a><a name="zh-cn_topic_0000001127125046_p74895716210"></a>说明：仅当item设置sticky属性时支持注册此事件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001127125046_section2279124532420"></a>

支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)。

## 示例<a name="zh-cn_topic_0000001127125046_section634316188515"></a>

详见[List示例](js-components-container-list.md#zh-cn_topic_0000001127284836_section24931424488)。

