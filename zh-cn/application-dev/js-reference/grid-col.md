# grid-col<a name="ZH-CN_TOPIC_0000001162414641"></a>

-   [权限列表](#zh-cn_topic_0000001063130862_section11257113618419)
-   [子组件](#zh-cn_topic_0000001063130862_section9288143101012)
-   [属性](#zh-cn_topic_0000001063130862_section1976213199113)
-   [样式](#zh-cn_topic_0000001063130862_section1948816404128)
-   [事件](#zh-cn_topic_0000001063130862_section94351031102113)
-   [示例](#zh-cn_topic_0000001063130862_section2021865273710)

grid-col是栅格布局容器grid-row的子容器组件。

## 权限列表<a name="zh-cn_topic_0000001063130862_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001063130862_section9288143101012"></a>

支持。

## 属性<a name="zh-cn_topic_0000001063130862_section1976213199113"></a>

<a name="zh-cn_topic_0000001063130862_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001063130862_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.449999999999999%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001063130862_p824610360217"><a name="zh-cn_topic_0000001063130862_p824610360217"></a><a name="zh-cn_topic_0000001063130862_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.83%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001063130862_row61510615123"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p13694117171213"><a name="zh-cn_topic_0000001063130862_p13694117171213"></a><a name="zh-cn_topic_0000001063130862_p13694117171213"></a>xs</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p17694191719123"><a name="zh-cn_topic_0000001063130862_p17694191719123"></a><a name="zh-cn_topic_0000001063130862_p17694191719123"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p9694171712125"><a name="zh-cn_topic_0000001063130862_p9694171712125"></a><a name="zh-cn_topic_0000001063130862_p9694171712125"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p769441711125"><a name="zh-cn_topic_0000001063130862_p769441711125"></a><a name="zh-cn_topic_0000001063130862_p769441711125"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p3694217141213"><a name="zh-cn_topic_0000001063130862_p3694217141213"></a><a name="zh-cn_topic_0000001063130862_p3694217141213"></a>在分辨率为xs模式下，设置该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row683183131212"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p15694417181219"><a name="zh-cn_topic_0000001063130862_p15694417181219"></a><a name="zh-cn_topic_0000001063130862_p15694417181219"></a>sm</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p15694141741210"><a name="zh-cn_topic_0000001063130862_p15694141741210"></a><a name="zh-cn_topic_0000001063130862_p15694141741210"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p66941517171212"><a name="zh-cn_topic_0000001063130862_p66941517171212"></a><a name="zh-cn_topic_0000001063130862_p66941517171212"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p4694111714123"><a name="zh-cn_topic_0000001063130862_p4694111714123"></a><a name="zh-cn_topic_0000001063130862_p4694111714123"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p17694117171211"><a name="zh-cn_topic_0000001063130862_p17694117171211"></a><a name="zh-cn_topic_0000001063130862_p17694117171211"></a>在分辨率为sm模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1211310592118"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p4694161710123"><a name="zh-cn_topic_0000001063130862_p4694161710123"></a><a name="zh-cn_topic_0000001063130862_p4694161710123"></a>md</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p569551751220"><a name="zh-cn_topic_0000001063130862_p569551751220"></a><a name="zh-cn_topic_0000001063130862_p569551751220"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p86952172121"><a name="zh-cn_topic_0000001063130862_p86952172121"></a><a name="zh-cn_topic_0000001063130862_p86952172121"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p3695171711214"><a name="zh-cn_topic_0000001063130862_p3695171711214"></a><a name="zh-cn_topic_0000001063130862_p3695171711214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p66953176126"><a name="zh-cn_topic_0000001063130862_p66953176126"></a><a name="zh-cn_topic_0000001063130862_p66953176126"></a>在分辨率为md模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row9263155681117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p10695101717122"><a name="zh-cn_topic_0000001063130862_p10695101717122"></a><a name="zh-cn_topic_0000001063130862_p10695101717122"></a>lg</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p5695131701217"><a name="zh-cn_topic_0000001063130862_p5695131701217"></a><a name="zh-cn_topic_0000001063130862_p5695131701217"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p1469501714124"><a name="zh-cn_topic_0000001063130862_p1469501714124"></a><a name="zh-cn_topic_0000001063130862_p1469501714124"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p1769511715127"><a name="zh-cn_topic_0000001063130862_p1769511715127"></a><a name="zh-cn_topic_0000001063130862_p1769511715127"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p8695111741217"><a name="zh-cn_topic_0000001063130862_p8695111741217"></a><a name="zh-cn_topic_0000001063130862_p8695111741217"></a>在分辨率为lg模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1236753141115"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p166957175127"><a name="zh-cn_topic_0000001063130862_p166957175127"></a><a name="zh-cn_topic_0000001063130862_p166957175127"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p1569561741210"><a name="zh-cn_topic_0000001063130862_p1569561741210"></a><a name="zh-cn_topic_0000001063130862_p1569561741210"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p17695201719121"><a name="zh-cn_topic_0000001063130862_p17695201719121"></a><a name="zh-cn_topic_0000001063130862_p17695201719121"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p156951617101214"><a name="zh-cn_topic_0000001063130862_p156951617101214"></a><a name="zh-cn_topic_0000001063130862_p156951617101214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p1169581712121"><a name="zh-cn_topic_0000001063130862_p1169581712121"></a><a name="zh-cn_topic_0000001063130862_p1169581712121"></a>在未设置明确断点时，默认占用列数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1348115011117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p12695141741216"><a name="zh-cn_topic_0000001063130862_p12695141741216"></a><a name="zh-cn_topic_0000001063130862_p12695141741216"></a>offset</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p0695131711124"><a name="zh-cn_topic_0000001063130862_p0695131711124"></a><a name="zh-cn_topic_0000001063130862_p0695131711124"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p8695111710129"><a name="zh-cn_topic_0000001063130862_p8695111710129"></a><a name="zh-cn_topic_0000001063130862_p8695111710129"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p15695111781220"><a name="zh-cn_topic_0000001063130862_p15695111781220"></a><a name="zh-cn_topic_0000001063130862_p15695111781220"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p2069531710128"><a name="zh-cn_topic_0000001063130862_p2069531710128"></a><a name="zh-cn_topic_0000001063130862_p2069531710128"></a>未设置具体分辨率模式下偏移时，当前元素延容器布局方向，默认偏移的列数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p42461736102118"><a name="zh-cn_topic_0000001063130862_p42461736102118"></a><a name="zh-cn_topic_0000001063130862_p42461736102118"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"></a>组件的唯一标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p17246836142119"><a name="zh-cn_topic_0000001063130862_p17246836142119"></a><a name="zh-cn_topic_0000001063130862_p17246836142119"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"></a>组件的样式声明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p324614367213"><a name="zh-cn_topic_0000001063130862_p324614367213"></a><a name="zh-cn_topic_0000001063130862_p324614367213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"></a>组件的样式类，用于引用样式表。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p1786251117156"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p1786251117156"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p1086241119157"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p1086241119157"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p586281111151"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p586281111151"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p1624612362219"><a name="zh-cn_topic_0000001063130862_p1624612362219"></a><a name="zh-cn_topic_0000001063130862_p1624612362219"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p113416153342"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p113416153342"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_p113416153342"></a>用来指定指向子元素<span id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_ph56099211134"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_ph56099211134"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_ph56099211134"></a>或子组件</span>的引用信息，该引用将注册到父组件的$refs 属性对象上。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1863421642313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p979mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p979mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p979mcpsimp"></a>disabled</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p981mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p981mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p981mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p983mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p983mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p983mcpsimp"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p192476368214"><a name="zh-cn_topic_0000001063130862_p192476368214"></a><a name="zh-cn_topic_0000001063130862_p192476368214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p985mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p985mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p985mcpsimp"></a>当前组件是否被禁用，在禁用场景下，组件将无法响应用户交互。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1263451617236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p22471736132114"><a name="zh-cn_topic_0000001063130862_p22471736132114"></a><a name="zh-cn_topic_0000001063130862_p22471736132114"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"></a>给当前组件设置data属性，进行相应的数据存储和读取。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001063130862_section1948816404128"></a>

<a name="zh-cn_topic_0000001063130862_table19959164918413"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001063130862_row695974912415"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.218778122187782%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.03869613038696%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.4991500849915%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001063130862_p0959184916417"><a name="zh-cn_topic_0000001063130862_p0959184916417"></a><a name="zh-cn_topic_0000001063130862_p0959184916417"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.12568743125688%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001063130862_row72422774310"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p106156422433"><a name="zh-cn_topic_0000001063130862_p106156422433"></a><a name="zh-cn_topic_0000001063130862_p106156422433"></a>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p46158429435"><a name="zh-cn_topic_0000001063130862_p46158429435"></a><a name="zh-cn_topic_0000001063130862_p46158429435"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p961534217431"><a name="zh-cn_topic_0000001063130862_p961534217431"></a><a name="zh-cn_topic_0000001063130862_p961534217431"></a>row</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p86151342174319"><a name="zh-cn_topic_0000001063130862_p86151342174319"></a><a name="zh-cn_topic_0000001063130862_p86151342174319"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p9615134214436"><a name="zh-cn_topic_0000001063130862_p9615134214436"></a><a name="zh-cn_topic_0000001063130862_p9615134214436"></a>flex容器主轴方向。可选项有：</p>
<a name="zh-cn_topic_0000001063130862_ul10615342184320"></a><a name="zh-cn_topic_0000001063130862_ul10615342184320"></a><ul id="zh-cn_topic_0000001063130862_ul10615342184320"><li>column：垂直方向从上到下</li><li>row：水平方向从左到右</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row324311719436"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p12616104254316"><a name="zh-cn_topic_0000001063130862_p12616104254316"></a><a name="zh-cn_topic_0000001063130862_p12616104254316"></a>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p1861624216433"><a name="zh-cn_topic_0000001063130862_p1861624216433"></a><a name="zh-cn_topic_0000001063130862_p1861624216433"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p26161242174317"><a name="zh-cn_topic_0000001063130862_p26161242174317"></a><a name="zh-cn_topic_0000001063130862_p26161242174317"></a>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p116166424431"><a name="zh-cn_topic_0000001063130862_p116166424431"></a><a name="zh-cn_topic_0000001063130862_p116166424431"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p13616842134313"><a name="zh-cn_topic_0000001063130862_p13616842134313"></a><a name="zh-cn_topic_0000001063130862_p13616842134313"></a>flex容器是单行还是多行显示，该值暂不支持动态修改。可选项有：</p>
<a name="zh-cn_topic_0000001063130862_ul136169424431"></a><a name="zh-cn_topic_0000001063130862_ul136169424431"></a><ul id="zh-cn_topic_0000001063130862_ul136169424431"><li>nowrap：不换行，单行显示。</li><li>wrap：换行，多行显示。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row11243147194319"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p961654212431"><a name="zh-cn_topic_0000001063130862_p961654212431"></a><a name="zh-cn_topic_0000001063130862_p961654212431"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p86163428431"><a name="zh-cn_topic_0000001063130862_p86163428431"></a><a name="zh-cn_topic_0000001063130862_p86163428431"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p26161142184319"><a name="zh-cn_topic_0000001063130862_p26161142184319"></a><a name="zh-cn_topic_0000001063130862_p26161142184319"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p1561694284310"><a name="zh-cn_topic_0000001063130862_p1561694284310"></a><a name="zh-cn_topic_0000001063130862_p1561694284310"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p176161342184317"><a name="zh-cn_topic_0000001063130862_p176161342184317"></a><a name="zh-cn_topic_0000001063130862_p176161342184317"></a>flex容器当前行的主轴对齐格式。可选项有：</p>
<a name="zh-cn_topic_0000001063130862_ul5616174210438"></a><a name="zh-cn_topic_0000001063130862_ul5616174210438"></a><ul id="zh-cn_topic_0000001063130862_ul5616174210438"><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row3243270439"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p12617942184311"><a name="zh-cn_topic_0000001063130862_p12617942184311"></a><a name="zh-cn_topic_0000001063130862_p12617942184311"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p15617194264312"><a name="zh-cn_topic_0000001063130862_p15617194264312"></a><a name="zh-cn_topic_0000001063130862_p15617194264312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p061744213433"><a name="zh-cn_topic_0000001063130862_p061744213433"></a><a name="zh-cn_topic_0000001063130862_p061744213433"></a>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p12617154214437"><a name="zh-cn_topic_0000001063130862_p12617154214437"></a><a name="zh-cn_topic_0000001063130862_p12617154214437"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p9617542124318"><a name="zh-cn_topic_0000001063130862_p9617542124318"></a><a name="zh-cn_topic_0000001063130862_p9617542124318"></a>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001063130862_ul166171442134312"></a><a name="zh-cn_topic_0000001063130862_ul166171442134312"></a><ul id="zh-cn_topic_0000001063130862_ul166171442134312"><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row924418734317"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p661810427433"><a name="zh-cn_topic_0000001063130862_p661810427433"></a><a name="zh-cn_topic_0000001063130862_p661810427433"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p186181042174316"><a name="zh-cn_topic_0000001063130862_p186181042174316"></a><a name="zh-cn_topic_0000001063130862_p186181042174316"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p19618144284315"><a name="zh-cn_topic_0000001063130862_p19618144284315"></a><a name="zh-cn_topic_0000001063130862_p19618144284315"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p461804254314"><a name="zh-cn_topic_0000001063130862_p461804254314"></a><a name="zh-cn_topic_0000001063130862_p461804254314"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p13619134216439"><a name="zh-cn_topic_0000001063130862_p13619134216439"></a><a name="zh-cn_topic_0000001063130862_p13619134216439"></a>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001063130862_ul56191424436"></a><a name="zh-cn_topic_0000001063130862_ul56191424436"></a><ul id="zh-cn_topic_0000001063130862_ul56191424436"><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row4448901436"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p166198429435"><a name="zh-cn_topic_0000001063130862_p166198429435"></a><a name="zh-cn_topic_0000001063130862_p166198429435"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p86191542144318"><a name="zh-cn_topic_0000001063130862_p86191542144318"></a><a name="zh-cn_topic_0000001063130862_p86191542144318"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p5619184218430"><a name="zh-cn_topic_0000001063130862_p5619184218430"></a><a name="zh-cn_topic_0000001063130862_p5619184218430"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p12619124234310"><a name="zh-cn_topic_0000001063130862_p12619124234310"></a><a name="zh-cn_topic_0000001063130862_p12619124234310"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p1861914421435"><a name="zh-cn_topic_0000001063130862_p1861914421435"></a><a name="zh-cn_topic_0000001063130862_p1861914421435"></a>确定该元素视图框的类型，该值暂不支持动态修改。可选值为：</p>
<a name="zh-cn_topic_0000001063130862_ul861920428436"></a><a name="zh-cn_topic_0000001063130862_ul861920428436"></a><ul id="zh-cn_topic_0000001063130862_ul861920428436"><li>flex：弹性布局</li><li>grid：网格布局</li><li>none：不渲染此元素</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row77805615421"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p5620184220430"><a name="zh-cn_topic_0000001063130862_p5620184220430"></a><a name="zh-cn_topic_0000001063130862_p5620184220430"></a>grid-template-[columns|rows]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p16206428434"><a name="zh-cn_topic_0000001063130862_p16206428434"></a><a name="zh-cn_topic_0000001063130862_p16206428434"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p146205423435"><a name="zh-cn_topic_0000001063130862_p146205423435"></a><a name="zh-cn_topic_0000001063130862_p146205423435"></a>1行1列</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p6620194215437"><a name="zh-cn_topic_0000001063130862_p6620194215437"></a><a name="zh-cn_topic_0000001063130862_p6620194215437"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p362010429434"><a name="zh-cn_topic_0000001063130862_p362010429434"></a><a name="zh-cn_topic_0000001063130862_p362010429434"></a>用于设置当前网格布局行和列的数量，不设置时默认1行1列，仅当display为grid时生效。</p>
<p id="zh-cn_topic_0000001063130862_p176201942154312"><a name="zh-cn_topic_0000001063130862_p176201942154312"></a><a name="zh-cn_topic_0000001063130862_p176201942154312"></a>示例：如设置grid-template-columns为：</p>
<p id="zh-cn_topic_0000001063130862_p062024213430"><a name="zh-cn_topic_0000001063130862_p062024213430"></a><a name="zh-cn_topic_0000001063130862_p062024213430"></a>(1) 50px 100px 60px：分三列，第一列50px，第二列100px，第三列60px；</p>
<p id="zh-cn_topic_0000001063130862_p126201742204315"><a name="zh-cn_topic_0000001063130862_p126201742204315"></a><a name="zh-cn_topic_0000001063130862_p126201742204315"></a>(2) 1fr 1fr 2fr：分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份；</p>
<p id="zh-cn_topic_0000001063130862_p6620142164312"><a name="zh-cn_topic_0000001063130862_p6620142164312"></a><a name="zh-cn_topic_0000001063130862_p6620142164312"></a>(3) 30% 20% 50%：分三列，将父组件允许的宽为基准，第一列占30%，第二列占20%，第三列占50%；</p>
<p id="zh-cn_topic_0000001063130862_p10620114264315"><a name="zh-cn_topic_0000001063130862_p10620114264315"></a><a name="zh-cn_topic_0000001063130862_p10620114264315"></a>(4) repeat(2,100px)：分两列，第一列100px，第二列100px；</p>
<p id="zh-cn_topic_0000001063130862_p4620164212437"><a name="zh-cn_topic_0000001063130862_p4620164212437"></a><a name="zh-cn_topic_0000001063130862_p4620164212437"></a>(5) auto 1fr 1fr：分三列，第一列自适应内部子组件所需宽度，剩余空间分为两等份，第二列占一份，第三列占一份。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row8906194914426"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p1462094219433"><a name="zh-cn_topic_0000001063130862_p1462094219433"></a><a name="zh-cn_topic_0000001063130862_p1462094219433"></a>grid-[columns|rows]-gap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p1762094215431"><a name="zh-cn_topic_0000001063130862_p1762094215431"></a><a name="zh-cn_topic_0000001063130862_p1762094215431"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p16621114219434"><a name="zh-cn_topic_0000001063130862_p16621114219434"></a><a name="zh-cn_topic_0000001063130862_p16621114219434"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p0621144214313"><a name="zh-cn_topic_0000001063130862_p0621144214313"></a><a name="zh-cn_topic_0000001063130862_p0621144214313"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p5621164210433"><a name="zh-cn_topic_0000001063130862_p5621164210433"></a><a name="zh-cn_topic_0000001063130862_p5621164210433"></a>用于设置行与行的间距或者列与列的间距，也可以支持通过grid-gap设置相同的行列间距，仅当display为grid时生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row63681446134219"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p56214422438"><a name="zh-cn_topic_0000001063130862_p56214422438"></a><a name="zh-cn_topic_0000001063130862_p56214422438"></a>grid-row-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p6621242164316"><a name="zh-cn_topic_0000001063130862_p6621242164316"></a><a name="zh-cn_topic_0000001063130862_p6621242164316"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p762154294314"><a name="zh-cn_topic_0000001063130862_p762154294314"></a><a name="zh-cn_topic_0000001063130862_p762154294314"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p1962114294317"><a name="zh-cn_topic_0000001063130862_p1962114294317"></a><a name="zh-cn_topic_0000001063130862_p1962114294317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p4621124244316"><a name="zh-cn_topic_0000001063130862_p4621124244316"></a><a name="zh-cn_topic_0000001063130862_p4621124244316"></a>用于设置当前元素在网格布局中的起止行号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1842574317422"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p1362154264312"><a name="zh-cn_topic_0000001063130862_p1362154264312"></a><a name="zh-cn_topic_0000001063130862_p1362154264312"></a>grid-column-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p2621174211439"><a name="zh-cn_topic_0000001063130862_p2621174211439"></a><a name="zh-cn_topic_0000001063130862_p2621174211439"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p1621124212439"><a name="zh-cn_topic_0000001063130862_p1621124212439"></a><a name="zh-cn_topic_0000001063130862_p1621124212439"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p15621124214313"><a name="zh-cn_topic_0000001063130862_p15621124214313"></a><a name="zh-cn_topic_0000001063130862_p15621124214313"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p562119425433"><a name="zh-cn_topic_0000001063130862_p562119425433"></a><a name="zh-cn_topic_0000001063130862_p562119425433"></a>用于设置当前元素在网格布局中的起止列号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1595144863117"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1079mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1079mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1079mcpsimp"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1081mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1081mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1081mcpsimp"></a>&lt;length&gt;<span id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_ph11748352163918"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_ph11748352163918"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_ph11748352163918"></a> | &lt;percentage&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1083mcpsimp"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1083mcpsimp"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1083mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p71741417194619"><a name="zh-cn_topic_0000001063130862_p71741417194619"></a><a name="zh-cn_topic_0000001063130862_p71741417194619"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_p1477601264"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_p1477601264"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_p1477601264"></a>设置组件自身的高度。</p>
<p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_p208761554184020"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_p208761554184020"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001050791158_p208761554184020"></a>缺省时使用元素自身内容需要的高度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row596084984110"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup1886516813013"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup1886516813013"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup1886516813013"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p19729127112814"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p19729127112814"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p19729127112814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p157435053316"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p157435053316"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p157435053316"></a>使用简写属性设置所有的内边距属性。</p>
<div class="p" id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a>该属性可以有1到4个值：<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul15202134923211"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul15202134923211"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul15202134923211"><li><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p10614155353215"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p10614155353215"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p10614155353215"></a>指定一个值时，该值指定四个边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p10614175393216"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p10614175393216"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p10614175393216"></a>指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p8614205393214"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p8614205393214"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p8614205393214"></a>指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p106141853193215"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p106141853193215"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p106141853193215"></a>指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。</p>
</li></ul>
</div>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row29611949164112"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup19949912807"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup19949912807"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup19949912807"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p11729374289"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p11729374289"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p11729374289"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a>设置左、上、右、下内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row11961184912413"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p769124717365"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p769124717365"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p157617124374"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p157617124374"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p157617124374"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup8490161513019"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup8490161513019"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_sup8490161513019"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1069144703616"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1069144703616"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1373027182819"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1373027182819"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1373027182819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1269184753610"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1269184753610"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1269184753610"></a>设置起始和末端内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row4963104994120"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p16963114984116"><a name="zh-cn_topic_0000001063130862_p16963114984116"></a><a name="zh-cn_topic_0000001063130862_p16963114984116"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a>使用简写属性设置所有的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置时，各属性值为默认值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row169631749164113"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p513631613319"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p513631613319"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p79641249184116"><a name="zh-cn_topic_0000001063130862_p79641249184116"></a><a name="zh-cn_topic_0000001063130862_p79641249184116"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p342285712314"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p342285712314"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p342285712314"></a>使用简写属性设置所有边框的样式，可选值为：</p>
<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1470834505612"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1470834505612"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1470834505612"><li>dotted：显示为一系列圆点，圆点半径为border-width的一半。</li><li>dashed：显示为一系列短的方形虚线。</li></ul>
<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul15621125545612"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul15621125545612"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul15621125545612"><li>solid：显示为一条实线。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row158901822154418"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_p589112225442"><a name="zh-cn_topic_0000001063130862_p589112225442"></a><a name="zh-cn_topic_0000001063130862_p589112225442"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_p6891102211445"><a name="zh-cn_topic_0000001063130862_p6891102211445"></a><a name="zh-cn_topic_0000001063130862_p6891102211445"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_p118911422104419"><a name="zh-cn_topic_0000001063130862_p118911422104419"></a><a name="zh-cn_topic_0000001063130862_p118911422104419"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p1891132284413"><a name="zh-cn_topic_0000001063130862_p1891132284413"></a><a name="zh-cn_topic_0000001063130862_p1891132284413"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_p16891102274415"><a name="zh-cn_topic_0000001063130862_p16891102274415"></a><a name="zh-cn_topic_0000001063130862_p16891102274415"></a>分别设置左、上、右、下四个边框的样式，可选值为dotted、dashed、solid。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row496412498416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p67303762810"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p67303762810"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p67303762810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a>使用简写属性设置对应位置的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置的值为默认值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row3965949124116"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p109652499414"><a name="zh-cn_topic_0000001063130862_p109652499414"></a><a name="zh-cn_topic_0000001063130862_p109652499414"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a>使用简写属性设置元素的所有边框宽度<span id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph13216153653618"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph13216153653618"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph13216153653618"></a>，或者单独为各边边框设置宽度</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row189651496412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p896584912413"><a name="zh-cn_topic_0000001063130862_p896584912413"></a><a name="zh-cn_topic_0000001063130862_p896584912413"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a>分别设置左、上、右、下四个边框的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row69651749144113"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p7966184984116"><a name="zh-cn_topic_0000001063130862_p7966184984116"></a><a name="zh-cn_topic_0000001063130862_p7966184984116"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a>使用简写属性设置元素的所有边框颜色<span id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph112821853719"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph112821853719"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph112821853719"></a>，或者单独为各边边框设置颜色</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row13966174910413"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_p59661649184117"><a name="zh-cn_topic_0000001063130862_p59661649184117"></a><a name="zh-cn_topic_0000001063130862_p59661649184117"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a>分别设置左、上、右、下四个边框的颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row396610497417"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p67306752816"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p67306752816"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p67306752816"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a>border-radius属性是设置元素的外边框圆角半径。<span id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph817510495223"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph817510495223"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ph817510495223"></a>设置border-radius时不能单独设置某一个方向的border-[left|top|right|bottom]-width，border-[left|top|right|bottom]-color ，border-[left|top|right|bottom]-style，如果要设置color、width和style，需要将四个方向一起设置（border-width、border-color、border-style）。</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row396604917417"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ac142d1054eee499f948069f46129c492"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p27305718283"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p27305718283"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p27305718283"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a>分别设置左上，右上，右下和左下四个角的圆角半径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row296744944115"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p15730197132811"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p15730197132811"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p15730197132811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a>仅支持设置<a href="渐变样式.md#ZH-CN_TOPIC_0000001115974726">渐变样式</a>，与background-color、background-image不兼容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1296744944115"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2977672444224b738a566c61225961c2"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p17730577282"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p17730577282"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p17730577282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a>设置背景颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row19672493414"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p7730976285"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p7730976285"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p7730976285"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a>设置背景图片。与background-color、background不兼容；支持本地图片资源地址。</p>
<p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p434668142510"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p434668142510"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p434668142510"></a>示例：</p>
<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul11766913172513"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul11766913172513"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul11766913172513"><li>background-image: url("/common/background.png")</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row6968174994111"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1065173641310"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1065173641310"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p137309714282"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p137309714282"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p137309714282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p91971112114318"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p91971112114318"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p91971112114318"></a>设置背景图片的大小。</p>
<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul41331853154111"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul41331853154111"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul41331853154111"><li>string可选值：<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul13611494111"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul13611494111"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul13611494111"><li>contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。</li><li>cover：把背景图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。</li><li>auto：保持原图的比例不变。</li></ul>
</li><li>length值参数方式：<p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1840244924418"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1840244924418"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1840244924418"></a>设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li><li>百分比参数方式：<p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p17936154410457"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p17936154410457"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p17936154410457"></a>以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row12969849174110"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1673015702810"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1673015702810"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1673015702810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a>针对重复背景图像样式进行设置，背景图像默认在水平和垂直方向上重复。</p>
<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul8236153103612"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul8236153103612"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul8236153103612"><li>repeat：在水平轴和竖直轴上同时重复绘制图片。</li><li>repeat-x：只在水平轴上重复绘制图片。</li><li>repeat-y：只在竖直轴上重复绘制图片。</li><li>no-repeat：不会重复绘制图片。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row9970104918413"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul8874155216502"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul8874155216502"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p173010720280"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p173010720280"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p173010720280"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1590812103363"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1590812103363"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1590812103363"><li>关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1453531734716"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1453531734716"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul1453531734716"><li>left：水平方向上最左侧。</li><li>right：水平方向上最右侧。</li><li>top：竖直方向上最顶部。</li><li>bottom：竖直方向上最底部。</li><li>center：水平方向或竖直方向上中间位置。</li></ul>
</li></ul>
<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul10908121023615"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul10908121023615"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul10908121023615"><li>length值参数方式：第一个值是水平位置，第二个值是垂直位置。 左上角是 0 0。单位是像素 (0px 0px)  。如果仅规定了一个值，另外一个值将是50%。</li><li>百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是 0% 0%。右下角是 100% 100%。如果仅规定了一个值，另外一个值为50%。</li><li>可以混合使用&lt;percentage&gt;和&lt;length&gt;</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1697134924117"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p134581712103910"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p134581712103910"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1873011722814"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1873011722814"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1873011722814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p122515161139"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p122515161139"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p122515161139"></a>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row19972174913414"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p15475737486"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p15475737486"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p15475737486"></a>string</p>
<p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a></p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p57301471281"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p57301471281"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p57301471281"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1568839154517"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1568839154517"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p1568839154517"></a>是否显示元素所产生的框。不可见的框会占用布局（将'display'属性设置为'none'来完全去除框），可选值为：</p>
<a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul751984164920"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul751984164920"></a><ul id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_ul751984164920"><li>visible：元素正常显示。</li><li>hidden：隐藏元素，但是其他元素的布局不改变，相当于此元素变成透明。</li></ul>
<div class="note" id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_note4549524649"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_note4549524649"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_note4549524649"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p25499241642"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p25499241642"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001059340528_p25499241642"></a>visibility和display样式都设置时，仅display生效</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001063130862_section94351031102113"></a>

<a name="zh-cn_topic_0000001063130862_table14104163373718"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001063130862_row9104173393711"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001063130862_row710443313711"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a>手指刚触摸屏幕时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row1210463313376"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a>手指触摸屏幕后移动时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row151052033153711"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a>手指触摸屏幕中动作被打断时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row161051433163710"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a>手指触摸结束离开屏幕时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row161051433123719"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a>点击动作触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row191052033143714"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a>长按动作触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001063130862_row19105133153711"></tr>
<tr id="zh-cn_topic_0000001063130862_row110643393712"></tr>
<tr id="zh-cn_topic_0000001063130862_row1510617331378"></tr>
<tr id="zh-cn_topic_0000001063130862_row11106533193718"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p12706561061"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p12706561061"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p12706561061"></a>swipe<sup id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_sup35424382912"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_sup35424382912"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p11711056161"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p11711056161"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p11711056161"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p2711556162"><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p2711556162"></a><a name="zh-cn_topic_0000001063130862_zh-cn_topic_0000001058460527_p2711556162"></a>组件上快速滑动后触发。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001063130862_section2021865273710"></a>

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

