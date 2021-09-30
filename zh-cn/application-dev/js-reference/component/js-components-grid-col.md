# grid-col<a name="ZH-CN_TOPIC_0000001163812228"></a>

-   [权限列表](#zh-cn_topic_0000001173164763_section11257113618419)
-   [子组件](#zh-cn_topic_0000001173164763_section9288143101012)
-   [属性](#zh-cn_topic_0000001173164763_section1976213199113)
-   [样式](#zh-cn_topic_0000001173164763_section1948816404128)
-   [事件](#zh-cn_topic_0000001173164763_section94351031102113)
-   [方法](#zh-cn_topic_0000001173164763_section2279124532420)
-   [示例](#zh-cn_topic_0000001173164763_section2021865273710)

grid-col是栅格布局容器grid-row的子容器组件。

## 权限列表<a name="zh-cn_topic_0000001173164763_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001173164763_section9288143101012"></a>

支持。

## 属性<a name="zh-cn_topic_0000001173164763_section1976213199113"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001173164763_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164763_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164763_a45273e2103004ff3bdd3375013e96a2a"><a name="zh-cn_topic_0000001173164763_a45273e2103004ff3bdd3375013e96a2a"></a><a name="zh-cn_topic_0000001173164763_a45273e2103004ff3bdd3375013e96a2a"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164763_ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="zh-cn_topic_0000001173164763_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="zh-cn_topic_0000001173164763_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164763_ab2ae3d9f60d6475ab95ba095851a9d07"><a name="zh-cn_topic_0000001173164763_ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="zh-cn_topic_0000001173164763_ab2ae3d9f60d6475ab95ba095851a9d07"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.449999999999999%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164763_p824610360217"><a name="zh-cn_topic_0000001173164763_p824610360217"></a><a name="zh-cn_topic_0000001173164763_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.83%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164763_af5c3b773ed0a42e589819a6c8d257ca1"><a name="zh-cn_topic_0000001173164763_af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="zh-cn_topic_0000001173164763_af5c3b773ed0a42e589819a6c8d257ca1"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164763_row61510615123"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p13694117171213"><a name="zh-cn_topic_0000001173164763_p13694117171213"></a><a name="zh-cn_topic_0000001173164763_p13694117171213"></a>xs</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p17694191719123"><a name="zh-cn_topic_0000001173164763_p17694191719123"></a><a name="zh-cn_topic_0000001173164763_p17694191719123"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p9694171712125"><a name="zh-cn_topic_0000001173164763_p9694171712125"></a><a name="zh-cn_topic_0000001173164763_p9694171712125"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p769441711125"><a name="zh-cn_topic_0000001173164763_p769441711125"></a><a name="zh-cn_topic_0000001173164763_p769441711125"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p3694217141213"><a name="zh-cn_topic_0000001173164763_p3694217141213"></a><a name="zh-cn_topic_0000001173164763_p3694217141213"></a>在分辨率为xs模式下，设置该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row683183131212"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p15694417181219"><a name="zh-cn_topic_0000001173164763_p15694417181219"></a><a name="zh-cn_topic_0000001173164763_p15694417181219"></a>sm</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p15694141741210"><a name="zh-cn_topic_0000001173164763_p15694141741210"></a><a name="zh-cn_topic_0000001173164763_p15694141741210"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p66941517171212"><a name="zh-cn_topic_0000001173164763_p66941517171212"></a><a name="zh-cn_topic_0000001173164763_p66941517171212"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p4694111714123"><a name="zh-cn_topic_0000001173164763_p4694111714123"></a><a name="zh-cn_topic_0000001173164763_p4694111714123"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p17694117171211"><a name="zh-cn_topic_0000001173164763_p17694117171211"></a><a name="zh-cn_topic_0000001173164763_p17694117171211"></a>在分辨率为sm模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row1211310592118"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p4694161710123"><a name="zh-cn_topic_0000001173164763_p4694161710123"></a><a name="zh-cn_topic_0000001173164763_p4694161710123"></a>md</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p569551751220"><a name="zh-cn_topic_0000001173164763_p569551751220"></a><a name="zh-cn_topic_0000001173164763_p569551751220"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p86952172121"><a name="zh-cn_topic_0000001173164763_p86952172121"></a><a name="zh-cn_topic_0000001173164763_p86952172121"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p3695171711214"><a name="zh-cn_topic_0000001173164763_p3695171711214"></a><a name="zh-cn_topic_0000001173164763_p3695171711214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p66953176126"><a name="zh-cn_topic_0000001173164763_p66953176126"></a><a name="zh-cn_topic_0000001173164763_p66953176126"></a>在分辨率为md模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row9263155681117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p10695101717122"><a name="zh-cn_topic_0000001173164763_p10695101717122"></a><a name="zh-cn_topic_0000001173164763_p10695101717122"></a>lg</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p5695131701217"><a name="zh-cn_topic_0000001173164763_p5695131701217"></a><a name="zh-cn_topic_0000001173164763_p5695131701217"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p1469501714124"><a name="zh-cn_topic_0000001173164763_p1469501714124"></a><a name="zh-cn_topic_0000001173164763_p1469501714124"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p1769511715127"><a name="zh-cn_topic_0000001173164763_p1769511715127"></a><a name="zh-cn_topic_0000001173164763_p1769511715127"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p8695111741217"><a name="zh-cn_topic_0000001173164763_p8695111741217"></a><a name="zh-cn_topic_0000001173164763_p8695111741217"></a>在分辨率为lg模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row1236753141115"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p166957175127"><a name="zh-cn_topic_0000001173164763_p166957175127"></a><a name="zh-cn_topic_0000001173164763_p166957175127"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p1569561741210"><a name="zh-cn_topic_0000001173164763_p1569561741210"></a><a name="zh-cn_topic_0000001173164763_p1569561741210"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p17695201719121"><a name="zh-cn_topic_0000001173164763_p17695201719121"></a><a name="zh-cn_topic_0000001173164763_p17695201719121"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p156951617101214"><a name="zh-cn_topic_0000001173164763_p156951617101214"></a><a name="zh-cn_topic_0000001173164763_p156951617101214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p1169581712121"><a name="zh-cn_topic_0000001173164763_p1169581712121"></a><a name="zh-cn_topic_0000001173164763_p1169581712121"></a>在未设置明确断点时，默认占用列数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row1348115011117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p12695141741216"><a name="zh-cn_topic_0000001173164763_p12695141741216"></a><a name="zh-cn_topic_0000001173164763_p12695141741216"></a>offset</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p0695131711124"><a name="zh-cn_topic_0000001173164763_p0695131711124"></a><a name="zh-cn_topic_0000001173164763_p0695131711124"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p8695111710129"><a name="zh-cn_topic_0000001173164763_p8695111710129"></a><a name="zh-cn_topic_0000001173164763_p8695111710129"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p15695111781220"><a name="zh-cn_topic_0000001173164763_p15695111781220"></a><a name="zh-cn_topic_0000001173164763_p15695111781220"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p2069531710128"><a name="zh-cn_topic_0000001173164763_p2069531710128"></a><a name="zh-cn_topic_0000001173164763_p2069531710128"></a>未设置具体分辨率模式下偏移时，当前元素延容器布局方向，默认偏移的列数</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173164763_section1948816404128"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001173164763_table282005513017"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164763_row168201855113012"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164763_p38201055113016"><a name="zh-cn_topic_0000001173164763_p38201055113016"></a><a name="zh-cn_topic_0000001173164763_p38201055113016"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.218778122187782%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164763_p3820105573010"><a name="zh-cn_topic_0000001173164763_p3820105573010"></a><a name="zh-cn_topic_0000001173164763_p3820105573010"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.03869613038696%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164763_p1282065593020"><a name="zh-cn_topic_0000001173164763_p1282065593020"></a><a name="zh-cn_topic_0000001173164763_p1282065593020"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.4991500849915%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164763_p2820455103013"><a name="zh-cn_topic_0000001173164763_p2820455103013"></a><a name="zh-cn_topic_0000001173164763_p2820455103013"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.12568743125688%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164763_p8820115573010"><a name="zh-cn_topic_0000001173164763_p8820115573010"></a><a name="zh-cn_topic_0000001173164763_p8820115573010"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164763_row482195519300"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p108211555183011"><a name="zh-cn_topic_0000001173164763_p108211555183011"></a><a name="zh-cn_topic_0000001173164763_p108211555183011"></a>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p6821185583020"><a name="zh-cn_topic_0000001173164763_p6821185583020"></a><a name="zh-cn_topic_0000001173164763_p6821185583020"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p108217558305"><a name="zh-cn_topic_0000001173164763_p108217558305"></a><a name="zh-cn_topic_0000001173164763_p108217558305"></a>row</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p168211655173015"><a name="zh-cn_topic_0000001173164763_p168211655173015"></a><a name="zh-cn_topic_0000001173164763_p168211655173015"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p18821165563017"><a name="zh-cn_topic_0000001173164763_p18821165563017"></a><a name="zh-cn_topic_0000001173164763_p18821165563017"></a>flex容器主轴方向。可选项有：</p>
<a name="zh-cn_topic_0000001173164763_ul15821145583019"></a><a name="zh-cn_topic_0000001173164763_ul15821145583019"></a><ul id="zh-cn_topic_0000001173164763_ul15821145583019"><li>column：垂直方向从上到下</li><li>row：水平方向从左到右</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row1582115513018"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p148211055133015"><a name="zh-cn_topic_0000001173164763_p148211055133015"></a><a name="zh-cn_topic_0000001173164763_p148211055133015"></a>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p0821055103010"><a name="zh-cn_topic_0000001173164763_p0821055103010"></a><a name="zh-cn_topic_0000001173164763_p0821055103010"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p118212557306"><a name="zh-cn_topic_0000001173164763_p118212557306"></a><a name="zh-cn_topic_0000001173164763_p118212557306"></a>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p168211155143015"><a name="zh-cn_topic_0000001173164763_p168211155143015"></a><a name="zh-cn_topic_0000001173164763_p168211155143015"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p1382145510309"><a name="zh-cn_topic_0000001173164763_p1382145510309"></a><a name="zh-cn_topic_0000001173164763_p1382145510309"></a>flex容器是单行还是多行显示，该值暂不支持动态修改。可选项有：</p>
<a name="zh-cn_topic_0000001173164763_ul282175510308"></a><a name="zh-cn_topic_0000001173164763_ul282175510308"></a><ul id="zh-cn_topic_0000001173164763_ul282175510308"><li>nowrap：不换行，单行显示。</li><li>wrap：换行，多行显示。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row782155583013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p1782175512303"><a name="zh-cn_topic_0000001173164763_p1782175512303"></a><a name="zh-cn_topic_0000001173164763_p1782175512303"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p88219557300"><a name="zh-cn_topic_0000001173164763_p88219557300"></a><a name="zh-cn_topic_0000001173164763_p88219557300"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p18821855173011"><a name="zh-cn_topic_0000001173164763_p18821855173011"></a><a name="zh-cn_topic_0000001173164763_p18821855173011"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p3821205517302"><a name="zh-cn_topic_0000001173164763_p3821205517302"></a><a name="zh-cn_topic_0000001173164763_p3821205517302"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p68219555307"><a name="zh-cn_topic_0000001173164763_p68219555307"></a><a name="zh-cn_topic_0000001173164763_p68219555307"></a>flex容器当前行的主轴对齐格式。可选项有：</p>
<a name="zh-cn_topic_0000001173164763_ul782165511302"></a><a name="zh-cn_topic_0000001173164763_ul782165511302"></a><ul id="zh-cn_topic_0000001173164763_ul782165511302"><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row182215556305"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p13822205523020"><a name="zh-cn_topic_0000001173164763_p13822205523020"></a><a name="zh-cn_topic_0000001173164763_p13822205523020"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p6822155519300"><a name="zh-cn_topic_0000001173164763_p6822155519300"></a><a name="zh-cn_topic_0000001173164763_p6822155519300"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p1982215523014"><a name="zh-cn_topic_0000001173164763_p1982215523014"></a><a name="zh-cn_topic_0000001173164763_p1982215523014"></a>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p14822655113020"><a name="zh-cn_topic_0000001173164763_p14822655113020"></a><a name="zh-cn_topic_0000001173164763_p14822655113020"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p17822555103011"><a name="zh-cn_topic_0000001173164763_p17822555103011"></a><a name="zh-cn_topic_0000001173164763_p17822555103011"></a>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001173164763_ul1822185512309"></a><a name="zh-cn_topic_0000001173164763_ul1822185512309"></a><ul id="zh-cn_topic_0000001173164763_ul1822185512309"><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row158231551309"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p108231055173010"><a name="zh-cn_topic_0000001173164763_p108231055173010"></a><a name="zh-cn_topic_0000001173164763_p108231055173010"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p98231455193012"><a name="zh-cn_topic_0000001173164763_p98231455193012"></a><a name="zh-cn_topic_0000001173164763_p98231455193012"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p108232055103011"><a name="zh-cn_topic_0000001173164763_p108232055103011"></a><a name="zh-cn_topic_0000001173164763_p108232055103011"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p198231155153019"><a name="zh-cn_topic_0000001173164763_p198231155153019"></a><a name="zh-cn_topic_0000001173164763_p198231155153019"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p1882312558307"><a name="zh-cn_topic_0000001173164763_p1882312558307"></a><a name="zh-cn_topic_0000001173164763_p1882312558307"></a>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001173164763_ul282335519305"></a><a name="zh-cn_topic_0000001173164763_ul282335519305"></a><ul id="zh-cn_topic_0000001173164763_ul282335519305"><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row782325510307"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p5823355143013"><a name="zh-cn_topic_0000001173164763_p5823355143013"></a><a name="zh-cn_topic_0000001173164763_p5823355143013"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p582325563018"><a name="zh-cn_topic_0000001173164763_p582325563018"></a><a name="zh-cn_topic_0000001173164763_p582325563018"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p68238557307"><a name="zh-cn_topic_0000001173164763_p68238557307"></a><a name="zh-cn_topic_0000001173164763_p68238557307"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p182315511303"><a name="zh-cn_topic_0000001173164763_p182315511303"></a><a name="zh-cn_topic_0000001173164763_p182315511303"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p1482375503018"><a name="zh-cn_topic_0000001173164763_p1482375503018"></a><a name="zh-cn_topic_0000001173164763_p1482375503018"></a>确定该元素视图框的类型，该值暂不支持动态修改。可选值为：</p>
<a name="zh-cn_topic_0000001173164763_ul6823155153010"></a><a name="zh-cn_topic_0000001173164763_ul6823155153010"></a><ul id="zh-cn_topic_0000001173164763_ul6823155153010"><li>flex：弹性布局</li><li>grid：网格布局</li><li>none：不渲染此元素</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row382411557307"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p48249553303"><a name="zh-cn_topic_0000001173164763_p48249553303"></a><a name="zh-cn_topic_0000001173164763_p48249553303"></a>grid-template-[columns|rows]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p0824115563014"><a name="zh-cn_topic_0000001173164763_p0824115563014"></a><a name="zh-cn_topic_0000001173164763_p0824115563014"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p7824185512308"><a name="zh-cn_topic_0000001173164763_p7824185512308"></a><a name="zh-cn_topic_0000001173164763_p7824185512308"></a>1行1列</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p782445523018"><a name="zh-cn_topic_0000001173164763_p782445523018"></a><a name="zh-cn_topic_0000001173164763_p782445523018"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p1082465513013"><a name="zh-cn_topic_0000001173164763_p1082465513013"></a><a name="zh-cn_topic_0000001173164763_p1082465513013"></a>用于设置当前网格布局行和列的数量，不设置时默认1行1列，仅当display为grid时生效。</p>
<p id="zh-cn_topic_0000001173164763_p18824145520305"><a name="zh-cn_topic_0000001173164763_p18824145520305"></a><a name="zh-cn_topic_0000001173164763_p18824145520305"></a>示例：如设置grid-template-columns为：</p>
<p id="zh-cn_topic_0000001173164763_p68241557304"><a name="zh-cn_topic_0000001173164763_p68241557304"></a><a name="zh-cn_topic_0000001173164763_p68241557304"></a>(1) 50px 100px 60px：分三列，第一列50px，第二列100px，第三列60px；</p>
<p id="zh-cn_topic_0000001173164763_p4824105513305"><a name="zh-cn_topic_0000001173164763_p4824105513305"></a><a name="zh-cn_topic_0000001173164763_p4824105513305"></a>(2) 1fr 1fr 2fr：分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份；</p>
<p id="zh-cn_topic_0000001173164763_p128242055163011"><a name="zh-cn_topic_0000001173164763_p128242055163011"></a><a name="zh-cn_topic_0000001173164763_p128242055163011"></a>(3) 30% 20% 50%：分三列，将父组件允许的宽为基准，第一列占30%，第二列占20%，第三列占50%；</p>
<p id="zh-cn_topic_0000001173164763_p282475514306"><a name="zh-cn_topic_0000001173164763_p282475514306"></a><a name="zh-cn_topic_0000001173164763_p282475514306"></a>(4) repeat(2,100px)：分两列，第一列100px，第二列100px；</p>
<p id="zh-cn_topic_0000001173164763_p17824185516300"><a name="zh-cn_topic_0000001173164763_p17824185516300"></a><a name="zh-cn_topic_0000001173164763_p17824185516300"></a>(5) auto 1fr 1fr：分三列，第一列自适应内部子组件所需宽度，剩余空间分为两等份，第二列占一份，第三列占一份。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row1882465518305"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p28241855183010"><a name="zh-cn_topic_0000001173164763_p28241855183010"></a><a name="zh-cn_topic_0000001173164763_p28241855183010"></a>grid-[columns|rows]-gap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p6824755103014"><a name="zh-cn_topic_0000001173164763_p6824755103014"></a><a name="zh-cn_topic_0000001173164763_p6824755103014"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p1282455553014"><a name="zh-cn_topic_0000001173164763_p1282455553014"></a><a name="zh-cn_topic_0000001173164763_p1282455553014"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p1824125515309"><a name="zh-cn_topic_0000001173164763_p1824125515309"></a><a name="zh-cn_topic_0000001173164763_p1824125515309"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p88241255183013"><a name="zh-cn_topic_0000001173164763_p88241255183013"></a><a name="zh-cn_topic_0000001173164763_p88241255183013"></a>用于设置行与行的间距或者列与列的间距，也可以支持通过grid-gap设置相同的行列间距，仅当display为grid时生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row10824135523013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p882475513307"><a name="zh-cn_topic_0000001173164763_p882475513307"></a><a name="zh-cn_topic_0000001173164763_p882475513307"></a>grid-row-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p19824205513018"><a name="zh-cn_topic_0000001173164763_p19824205513018"></a><a name="zh-cn_topic_0000001173164763_p19824205513018"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p7824105523012"><a name="zh-cn_topic_0000001173164763_p7824105523012"></a><a name="zh-cn_topic_0000001173164763_p7824105523012"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p782445503011"><a name="zh-cn_topic_0000001173164763_p782445503011"></a><a name="zh-cn_topic_0000001173164763_p782445503011"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p13824115519302"><a name="zh-cn_topic_0000001173164763_p13824115519302"></a><a name="zh-cn_topic_0000001173164763_p13824115519302"></a>用于设置当前元素在网格布局中的起止行号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164763_row1582495513010"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164763_p48247556301"><a name="zh-cn_topic_0000001173164763_p48247556301"></a><a name="zh-cn_topic_0000001173164763_p48247556301"></a>grid-column-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164763_p2825455183011"><a name="zh-cn_topic_0000001173164763_p2825455183011"></a><a name="zh-cn_topic_0000001173164763_p2825455183011"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164763_p1382545583012"><a name="zh-cn_topic_0000001173164763_p1382545583012"></a><a name="zh-cn_topic_0000001173164763_p1382545583012"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164763_p382515553016"><a name="zh-cn_topic_0000001173164763_p382515553016"></a><a name="zh-cn_topic_0000001173164763_p382515553016"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164763_p128256553309"><a name="zh-cn_topic_0000001173164763_p128256553309"></a><a name="zh-cn_topic_0000001173164763_p128256553309"></a>用于设置当前元素在网格布局中的起止列号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持宽度相关样式。

## 事件<a name="zh-cn_topic_0000001173164763_section94351031102113"></a>

支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)。

## 方法<a name="zh-cn_topic_0000001173164763_section2279124532420"></a>

支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)。

## 示例<a name="zh-cn_topic_0000001173164763_section2021865273710"></a>

```
<!-- index.hml -->
<div class="container">
  <grid-container id="mygrid" columns="5" gutter="20px" style="background-color: pink;">
    <grid-row style="height:400px;justify-content:space-around;">
      <grid-col span="1">
        <div style="align-items: center;justify-content: center;height: 100%;width: 100%;">
          <text style="color: dodgerblue;" onclick="getCol">內容元素</text>
        </div>
      </grid-col>
      <grid-col span="4" style="background-color:orange;">
        <div style="width: 100%;height: 100%;padding: 20px;align-items: center;">
          <text onclick="getColWidth">內容元素</text>
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

