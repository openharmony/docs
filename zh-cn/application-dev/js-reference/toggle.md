# toggle<a name="ZH-CN_TOPIC_0000001115974750"></a>

-   [权限列表](#zh-cn_topic_0000001061155984_section11257113618419)
-   [子组件](#zh-cn_topic_0000001061155984_section9288143101012)
-   [属性](#zh-cn_topic_0000001061155984_section2598341175212)
-   [样式](#zh-cn_topic_0000001061155984_section3655917541)
-   [事件](#zh-cn_topic_0000001061155984_section3892191911214)
-   [示例](#zh-cn_topic_0000001061155984_section520313404174)

状态按钮用于从一组选项中进行选择，并可能在界面上实时显示选择后的结果。通常这一组选项都是由状态按钮构成。

>![](public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 5 开始支持。

## 权限列表<a name="zh-cn_topic_0000001061155984_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001061155984_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001061155984_section2598341175212"></a>

<a name="zh-cn_topic_0000001061155984_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001061155984_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001061155984_p2063810588455"><a name="zh-cn_topic_0000001061155984_p2063810588455"></a><a name="zh-cn_topic_0000001061155984_p2063810588455"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001061155984_row128581827123812"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p158151581017"><a name="zh-cn_topic_0000001061155984_p158151581017"></a><a name="zh-cn_topic_0000001061155984_p158151581017"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p98151887118"><a name="zh-cn_topic_0000001061155984_p98151887118"></a><a name="zh-cn_topic_0000001061155984_p98151887118"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p78158817112"><a name="zh-cn_topic_0000001061155984_p78158817112"></a><a name="zh-cn_topic_0000001061155984_p78158817112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p8638135854515"><a name="zh-cn_topic_0000001061155984_p8638135854515"></a><a name="zh-cn_topic_0000001061155984_p8638135854515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p1981514819118"><a name="zh-cn_topic_0000001061155984_p1981514819118"></a><a name="zh-cn_topic_0000001061155984_p1981514819118"></a>toggle组件的文本值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1314733811"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p14144703815"><a name="zh-cn_topic_0000001061155984_p14144703815"></a><a name="zh-cn_topic_0000001061155984_p14144703815"></a>checked</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p174104714389"><a name="zh-cn_topic_0000001061155984_p174104714389"></a><a name="zh-cn_topic_0000001061155984_p174104714389"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p174134719389"><a name="zh-cn_topic_0000001061155984_p174134719389"></a><a name="zh-cn_topic_0000001061155984_p174134719389"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p86381558144516"><a name="zh-cn_topic_0000001061155984_p86381558144516"></a><a name="zh-cn_topic_0000001061155984_p86381558144516"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p184114763819"><a name="zh-cn_topic_0000001061155984_p184114763819"></a><a name="zh-cn_topic_0000001061155984_p184114763819"></a>toggle组件是否被选中。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row9193183195312"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p7638658124519"><a name="zh-cn_topic_0000001061155984_p7638658124519"></a><a name="zh-cn_topic_0000001061155984_p7638658124519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"></a>组件的唯一标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1219312385317"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p1763945824512"><a name="zh-cn_topic_0000001061155984_p1763945824512"></a><a name="zh-cn_topic_0000001061155984_p1763945824512"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"></a>组件的样式声明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row16193133125319"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p1639158154514"><a name="zh-cn_topic_0000001061155984_p1639158154514"></a><a name="zh-cn_topic_0000001061155984_p1639158154514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"></a>组件的样式类，用于引用样式表。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row71931634531"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p1786251117156"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p1786251117156"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p1086241119157"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p1086241119157"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p586281111151"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p586281111151"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p1763912586457"><a name="zh-cn_topic_0000001061155984_p1763912586457"></a><a name="zh-cn_topic_0000001061155984_p1763912586457"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p113416153342"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p113416153342"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_p113416153342"></a>用来指定指向子元素<span id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_ph56099211134"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_ph56099211134"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_ph56099211134"></a>或子组件</span>的引用信息，该引用将注册到父组件的$refs 属性对象上。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row15193153155316"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p979mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p979mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p979mcpsimp"></a>disabled</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p981mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p981mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p981mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p983mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p983mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p983mcpsimp"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p863913581451"><a name="zh-cn_topic_0000001061155984_p863913581451"></a><a name="zh-cn_topic_0000001061155984_p863913581451"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p985mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p985mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p985mcpsimp"></a>当前组件是否被禁用，在禁用场景下，组件将无法响应用户交互。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row151931836536"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p06397586457"><a name="zh-cn_topic_0000001061155984_p06397586457"></a><a name="zh-cn_topic_0000001061155984_p06397586457"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"></a>给当前组件设置data属性，进行相应的数据存储和读取。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001061155984_section3655917541"></a>

<a name="zh-cn_topic_0000001061155984_table1744514388541"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001061155984_row1244614388545"><th class="cellrowborder" valign="top" width="17.928207179282072%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.088591140885912%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="21.41785821417858%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.979302069793021%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001061155984_p117421754619"><a name="zh-cn_topic_0000001061155984_p117421754619"></a><a name="zh-cn_topic_0000001061155984_p117421754619"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="39.58604139586041%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001061155984_row2048791993512"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p1239116217355"><a name="zh-cn_topic_0000001061155984_p1239116217355"></a><a name="zh-cn_topic_0000001061155984_p1239116217355"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p23912219356"><a name="zh-cn_topic_0000001061155984_p23912219356"></a><a name="zh-cn_topic_0000001061155984_p23912219356"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p18391122114351"><a name="zh-cn_topic_0000001061155984_p18391122114351"></a><a name="zh-cn_topic_0000001061155984_p18391122114351"></a>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p12391182113514"><a name="zh-cn_topic_0000001061155984_p12391182113514"></a><a name="zh-cn_topic_0000001061155984_p12391182113514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p1839116217353"><a name="zh-cn_topic_0000001061155984_p1839116217353"></a><a name="zh-cn_topic_0000001061155984_p1839116217353"></a>按钮的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row178272168352"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p939172117357"><a name="zh-cn_topic_0000001061155984_p939172117357"></a><a name="zh-cn_topic_0000001061155984_p939172117357"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p539119214356"><a name="zh-cn_topic_0000001061155984_p539119214356"></a><a name="zh-cn_topic_0000001061155984_p539119214356"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p153915215356"><a name="zh-cn_topic_0000001061155984_p153915215356"></a><a name="zh-cn_topic_0000001061155984_p153915215356"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p0391521183511"><a name="zh-cn_topic_0000001061155984_p0391521183511"></a><a name="zh-cn_topic_0000001061155984_p0391521183511"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p439162118359"><a name="zh-cn_topic_0000001061155984_p439162118359"></a><a name="zh-cn_topic_0000001061155984_p439162118359"></a>按钮的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row128281916173519"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p5391521103516"><a name="zh-cn_topic_0000001061155984_p5391521103516"></a><a name="zh-cn_topic_0000001061155984_p5391521103516"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p1839172113516"><a name="zh-cn_topic_0000001061155984_p1839172113516"></a><a name="zh-cn_topic_0000001061155984_p1839172113516"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p6391162111359"><a name="zh-cn_topic_0000001061155984_p6391162111359"></a><a name="zh-cn_topic_0000001061155984_p6391162111359"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p0392102143513"><a name="zh-cn_topic_0000001061155984_p0392102143513"></a><a name="zh-cn_topic_0000001061155984_p0392102143513"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p143921121153510"><a name="zh-cn_topic_0000001061155984_p143921121153510"></a><a name="zh-cn_topic_0000001061155984_p143921121153510"></a>按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="zh-cn_topic_0000001061155984_note18392202114356"><a name="zh-cn_topic_0000001061155984_note18392202114356"></a><a name="zh-cn_topic_0000001061155984_note18392202114356"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001061155984_p2392162117358"><a name="zh-cn_topic_0000001061155984_p2392162117358"></a><a name="zh-cn_topic_0000001061155984_p2392162117358"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row15828111619355"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p16392162123518"><a name="zh-cn_topic_0000001061155984_p16392162123518"></a><a name="zh-cn_topic_0000001061155984_p16392162123518"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p14392221153518"><a name="zh-cn_topic_0000001061155984_p14392221153518"></a><a name="zh-cn_topic_0000001061155984_p14392221153518"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p7392192163514"><a name="zh-cn_topic_0000001061155984_p7392192163514"></a><a name="zh-cn_topic_0000001061155984_p7392192163514"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p8392162110352"><a name="zh-cn_topic_0000001061155984_p8392162110352"></a><a name="zh-cn_topic_0000001061155984_p8392162110352"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p14392162118356"><a name="zh-cn_topic_0000001061155984_p14392162118356"></a><a name="zh-cn_topic_0000001061155984_p14392162118356"></a>按钮的字体样式。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row10828111616352"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p9392142183516"><a name="zh-cn_topic_0000001061155984_p9392142183516"></a><a name="zh-cn_topic_0000001061155984_p9392142183516"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p1439212212355"><a name="zh-cn_topic_0000001061155984_p1439212212355"></a><a name="zh-cn_topic_0000001061155984_p1439212212355"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p93928219354"><a name="zh-cn_topic_0000001061155984_p93928219354"></a><a name="zh-cn_topic_0000001061155984_p93928219354"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p5392152111359"><a name="zh-cn_topic_0000001061155984_p5392152111359"></a><a name="zh-cn_topic_0000001061155984_p5392152111359"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p939202114352"><a name="zh-cn_topic_0000001061155984_p939202114352"></a><a name="zh-cn_topic_0000001061155984_p939202114352"></a>按钮的字体粗细。见<a href="text.md#zh-cn_topic_0000001058830803_section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row11297118352"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_p173926212355"><a name="zh-cn_topic_0000001061155984_p173926212355"></a><a name="zh-cn_topic_0000001061155984_p173926212355"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_p1939332112358"><a name="zh-cn_topic_0000001061155984_p1939332112358"></a><a name="zh-cn_topic_0000001061155984_p1939332112358"></a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_p73931215356"><a name="zh-cn_topic_0000001061155984_p73931215356"></a><a name="zh-cn_topic_0000001061155984_p73931215356"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p139312218359"><a name="zh-cn_topic_0000001061155984_p139312218359"></a><a name="zh-cn_topic_0000001061155984_p139312218359"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_p1039352115354"><a name="zh-cn_topic_0000001061155984_p1039352115354"></a><a name="zh-cn_topic_0000001061155984_p1039352115354"></a>按钮的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="自定义字体样式.md#ZH-CN_TOPIC_0000001162414611">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row180716316012"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1070mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1070mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1070mcpsimp"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1072mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1072mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1072mcpsimp"></a>&lt;length&gt;<span id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph597168143913"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph597168143913"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph597168143913"></a> | &lt;percentage&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p3948114217528"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p3948114217528"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p3948114217528"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p13174101704612"><a name="zh-cn_topic_0000001061155984_p13174101704612"></a><a name="zh-cn_topic_0000001061155984_p13174101704612"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p624653010258"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p624653010258"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p624653010258"></a>设置组件自身的宽度。</p>
<p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p84811050134010"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p84811050134010"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p84811050134010"></a>缺省时使用元素自身内容需要的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row168079320018"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1079mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1079mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1079mcpsimp"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1081mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1081mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1081mcpsimp"></a>&lt;length&gt;<span id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph11748352163918"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph11748352163918"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph11748352163918"></a> | &lt;percentage&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1083mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1083mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1083mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p71741417194619"><a name="zh-cn_topic_0000001061155984_p71741417194619"></a><a name="zh-cn_topic_0000001061155984_p71741417194619"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1477601264"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1477601264"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1477601264"></a>设置组件自身的高度。</p>
<p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p208761554184020"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p208761554184020"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p208761554184020"></a>缺省时使用元素自身内容需要的高度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row16807233020"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1088mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1088mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1088mcpsimp"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1090mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1090mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1090mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1092mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1092mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1092mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p19729127112814"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p19729127112814"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p19729127112814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><div class="p" id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1094mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1094mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1094mcpsimp"></a>该属性可以有1到4个值：<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul15202134923211"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul15202134923211"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul15202134923211"><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p10614155353215"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p10614155353215"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p10614155353215"></a>指定一个值时，该值指定四个边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p10614175393216"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p10614175393216"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p10614175393216"></a>指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p8614205393214"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p8614205393214"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p8614205393214"></a>指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p106141853193215"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p106141853193215"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p106141853193215"></a>指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。</p>
</li></ul>
</div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row128078314011"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1097mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1097mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1097mcpsimp"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1099mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1099mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1099mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1101mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1101mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1101mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p11729374289"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p11729374289"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p11729374289"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1103mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1103mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1103mcpsimp"></a>设置左、上、右、下内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row178071934012"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p769124717365"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p769124717365"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p157617124374"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p157617124374"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p157617124374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1069144703616"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1069144703616"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1373027182819"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1373027182819"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1373027182819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1269184753610"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1269184753610"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1269184753610"></a>设置起始和末端内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1080713405"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1106mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1106mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1106mcpsimp"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1108mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1108mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1108mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1110mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1110mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1110mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p4730774285"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p4730774285"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p4730774285"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1112mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1112mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1112mcpsimp"></a>使用简写属性设置所有的外边距属性，该属性可以有1到4个值。</p>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul5333133311105"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul5333133311105"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul5333133311105"><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p03345339103"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p03345339103"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p03345339103"></a>只有一个值时，这个值会被指定给全部的四个边。</p>
</li><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1133420334108"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1133420334108"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1133420334108"></a>两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。</p>
</li><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p193341533191015"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p193341533191015"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p193341533191015"></a>三个值时，第一个值被匹配给上, 第二个值被匹配给左和右，第三个值被匹配给下。</p>
</li><li><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p733412334102"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p733412334102"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p733412334102"></a>四个值时，会依次按上、右、下、左的顺序匹配 (即顺时针顺序)。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row11806831809"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1115mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1115mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1115mcpsimp"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1117mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1117mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1117mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1119mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1119mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1119mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p773013742811"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p773013742811"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p773013742811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1121mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1121mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1121mcpsimp"></a>设置左、上、右、下外边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1680633402"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p9492107123816"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p9492107123816"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p157617124374_1"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p157617124374_1"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p157617124374_1"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1549213793811"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1549213793811"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p117511744618"><a name="zh-cn_topic_0000001061155984_p117511744618"></a><a name="zh-cn_topic_0000001061155984_p117511744618"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1049212715388"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1049212715388"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1049212715388"></a>设置起始和末端外边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row13805731308"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1207mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1207mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1207mcpsimp"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1209mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1209mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1209mcpsimp"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1211mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1211mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1211mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p15730197132811"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p15730197132811"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p15730197132811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a>仅支持设置<a href="渐变样式.md#ZH-CN_TOPIC_0000001115974726">渐变样式</a>，与background-color、background-image不兼容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1280593701"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1217mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1217mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1217mcpsimp"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1219mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1219mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1219mcpsimp"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1221mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1221mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1221mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p17730577282"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p17730577282"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p17730577282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1223mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1223mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1223mcpsimp"></a>设置背景颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row8805173901"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1226mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1226mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1226mcpsimp"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1228mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1228mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1228mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1230mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1230mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1230mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p7730976285"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p7730976285"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p7730976285"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1232mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1232mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1232mcpsimp"></a>设置背景图片。与background-color、background不兼容；支持本地图片资源地址。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row118052031605"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p15157115065817"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p15157115065817"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p15157115065817"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1065173641310"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1065173641310"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p8157195019585"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p8157195019585"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p8157195019585"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p137309714282"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p137309714282"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p137309714282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p91971112114318"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p91971112114318"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p91971112114318"></a>设置背景图片的大小。</p>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul41331853154111"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul41331853154111"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul41331853154111"><li>string可选值：<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul13611494111"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul13611494111"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul13611494111"><li>contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。</li><li>cover：把背景图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。</li><li>auto：保持原图的比例不变。</li></ul>
</li><li>length值参数方式：<p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1840244924418"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1840244924418"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1840244924418"></a>设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li><li>百分比参数方式：<p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p17936154410457"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p17936154410457"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p17936154410457"></a>以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row480563806"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1235mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1235mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1235mcpsimp"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1237mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1237mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1237mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1239mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1239mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1239mcpsimp"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1673015702810"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1673015702810"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1673015702810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1241mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1241mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1241mcpsimp"></a>针对重复背景图像样式进行设置，背景图像默认在水平和垂直方向上重复。</p>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul8236153103612"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul8236153103612"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul8236153103612"><li>repeat：在水平轴和竖直轴上同时重复绘制图片。</li><li>repeat-x：只在水平轴上重复绘制图片。</li><li>repeat-y：只在竖直轴上重复绘制图片。</li><li>no-repeat：不会重复绘制图片。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row18054318017"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1244mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1244mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1244mcpsimp"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul8874155216502"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul8874155216502"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1248mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1248mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1248mcpsimp"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p173010720280"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p173010720280"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p173010720280"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1590812103363"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1590812103363"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1590812103363"><li>关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1453531734716"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1453531734716"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul1453531734716"><li>left：水平方向上最左侧。</li><li>right：水平方向上最右侧。</li><li>top：竖直方向上最顶部。</li><li>bottom：竖直方向上最底部。</li><li>center：水平方向或竖直方向上中间位置。</li></ul>
</li></ul>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul10908121023615"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul10908121023615"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul10908121023615"><li>length值参数方式：第一个值是水平位置，第二个值是垂直位置。 左上角是 0 0。单位是像素 (0px 0px)  。如果仅规定了一个值，另外一个值将是50%。</li><li>百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是 0% 0%。右下角是 100% 100%。如果仅规定了一个值，另外一个值为50%。</li><li>可以混合使用&lt;percentage&gt;和&lt;length&gt;</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row138059310014"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p134581712103910"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p134581712103910"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1267mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1267mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1267mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1269mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1269mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1269mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1873011722814"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1873011722814"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1873011722814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p122515161139"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p122515161139"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p122515161139"></a>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row780563408"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1274mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1274mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1274mcpsimp"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1544115441446"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1544115441446"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1544115441446"></a>string</p>
<p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1276mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1276mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1276mcpsimp"></a></p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1278mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1278mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1278mcpsimp"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p167303762818"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p167303762818"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p167303762818"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p23704018414"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p23704018414"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p23704018414"></a>确定一个元素所产生的框的类型，可选值为：</p>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul12227103394916"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul12227103394916"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul12227103394916"><li>flex：弹性布局。</li><li>none：不渲染此元素。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1805331306"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1283mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1283mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1283mcpsimp"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p15475737486"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p15475737486"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p15475737486"></a>string</p>
<p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1285mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1285mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1285mcpsimp"></a></p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1287mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1287mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1287mcpsimp"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p57301471281"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p57301471281"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p57301471281"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1568839154517"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1568839154517"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1568839154517"></a>是否显示元素所产生的框。不可见的框会占用布局（将'display'属性设置为'none'来完全去除框），可选值为：</p>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul751984164920"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul751984164920"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul751984164920"><li>visible：元素正常显示。</li><li>hidden：隐藏元素，但是其他元素的布局不改变，相当于此元素变成透明。</li></ul>
<div class="note" id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note4549524649"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note4549524649"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note4549524649"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p25499241642"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p25499241642"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p25499241642"></a>visibility和display样式都设置时，仅display生效</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row11805123204"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1292mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1292mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1292mcpsimp"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1294mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1294mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1294mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1296mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1296mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1296mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1373057132812"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1373057132812"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1373057132812"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1298mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1298mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1298mcpsimp"></a>规定当前组件如何适应父组件中的可用空间。它作为一个简写属性，用来设置组件的flex-grow。</p>
<div class="note" id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note34891253201520"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note34891253201520"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note34891253201520"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1248915538152"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1248915538152"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1248915538152"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row780419318011"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1301mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1301mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1301mcpsimp"></a>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1303mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1303mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1303mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1305mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1305mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1305mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p81768178466"><a name="zh-cn_topic_0000001061155984_p81768178466"></a><a name="zh-cn_topic_0000001061155984_p81768178466"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p4437122419557"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p4437122419557"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p4437122419557"></a>设置组件的拉伸样式，指定父组件容器主轴方向上剩余空间（容器本身大小减去所有flex子元素占用的大小）的分配权重。0为不伸展。</p>
<div class="note" id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note201231734212"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note201231734212"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note201231734212"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p184555314553"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p184555314553"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p184555314553"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1980415318018"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1310mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1310mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1310mcpsimp"></a>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1312mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1312mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1312mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1314mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1314mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1314mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p1917613178465"><a name="zh-cn_topic_0000001061155984_p1917613178465"></a><a name="zh-cn_topic_0000001061155984_p1917613178465"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1316mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1316mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1316mcpsimp"></a>设置组件的收缩样式，元素仅在默认宽度之和大于容器的时候才会发生收缩，0为不收缩。</p>
<div class="note" id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note147160917217"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note147160917217"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note147160917217"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p844914328577"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p844914328577"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p844914328577"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row198042032012"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1319mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1319mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1319mcpsimp"></a>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1148910787"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1148910787"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1148910787"></a>&lt;length&gt;</p>
<p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1321mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1321mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1321mcpsimp"></a></p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1323mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1323mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1323mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_p0176817154612"><a name="zh-cn_topic_0000001061155984_p0176817154612"></a><a name="zh-cn_topic_0000001061155984_p0176817154612"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1325mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1325mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1325mcpsimp"></a>设置组件在主轴方向上的初始大小。</p>
<div class="note" id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note62848141222"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note62848141222"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note62848141222"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p16711745115718"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p16711745115718"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p16711745115718"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row16804638012"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1328mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1328mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1328mcpsimp"></a>position</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1330mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1330mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1330mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1332mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1332mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1332mcpsimp"></a>relative</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1173107172814"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1173107172814"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1173107172814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1334mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1334mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1334mcpsimp"></a>设置元素的定位类型，不支持动态变更。</p>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul17185232185014"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul17185232185014"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul17185232185014"><li>fixed：相对与整个界面进行定位。</li><li>absolute：相对于父元素进行定位。</li><li>relative：相对于其正常位置进行定位。</li></ul>
<div class="note" id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note167617191219"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note167617191219"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_note167617191219"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1839092815101"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1839092815101"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1839092815101"></a>absolute属性仅在父容器为&lt;div&gt;、&lt;stack&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row9804632019"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1337mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1337mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1337mcpsimp"></a>[left|top<span id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph14927143614712"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph14927143614712"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph14927143614712"></a>|right|bottom</span>]</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1849062221214"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1849062221214"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p1849062221214"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1341mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1341mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1341mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p187314719288"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p187314719288"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_p187314719288"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1343mcpsimp"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1343mcpsimp"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1343mcpsimp"></a>left|top<span id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph116191353154713"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph116191353154713"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ph116191353154713"></a>|right|bottom</span>需要配合position样式使用，来确定元素的偏移位置。</p>
<a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul12671003525"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul12671003525"></a><ul id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001050791158_ul12671003525"><li>left属性规定元素的左边缘。该属性定义了定位元素左外边距边界与其包含块左边界之间的偏移。</li><li>top属性规定元素的顶部边缘。该属性定义了一个定位元素的上外边距边界与其包含块上边界之间的偏移。</li><li>right属性规定元素的右边缘。该属性定义了定位元素右外边距边界与其包含块右边界之间的偏移。</li><li>bottom属性规定元素的底部边缘。该属性定义了一个定位元素的下外边距边界与其包含块下边界之间的偏移。</li></ul>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001061155984_section3892191911214"></a>

<a name="zh-cn_topic_0000001061155984_table101871711203115"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001061155984_row1718751111316"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001061155984_row105681412318"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_p18889152411316"><a name="zh-cn_topic_0000001061155984_p18889152411316"></a><a name="zh-cn_topic_0000001061155984_p18889152411316"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_p138891924103112"><a name="zh-cn_topic_0000001061155984_p138891924103112"></a><a name="zh-cn_topic_0000001061155984_p138891924103112"></a>{ checked：isChecked }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_p1889002418312"><a name="zh-cn_topic_0000001061155984_p1889002418312"></a><a name="zh-cn_topic_0000001061155984_p1889002418312"></a>组件选中状态发生变化时触发。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row336512569516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a>手指刚触摸屏幕时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1236519563517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a>手指触摸屏幕后移动时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row18365145615516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a>手指触摸屏幕中动作被打断时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row63651566517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a>手指触摸结束离开屏幕时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row1536575611516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a>点击动作触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row183661256758"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a>长按动作触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001061155984_row5366185613517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p12706561061"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p12706561061"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p12706561061"></a>swipe<sup id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_sup35424382912"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_sup35424382912"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p11711056161"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p11711056161"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p11711056161"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p2711556162"><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p2711556162"></a><a name="zh-cn_topic_0000001061155984_zh-cn_topic_0000001058460527_p2711556162"></a>组件上快速滑动后触发。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001061155984_section520313404174"></a>

```
<!-- xxx.hml -->
<div style="flex-direction: column;">
  <text class="margin">1. Multiple choice example</text>
  <div style="flex-wrap: wrap">
    <toggle class="margin" for="{{toggles}}">{{$item}}</toggle>
  </div>
  <text class="margin">2. Single choice example</text>
  <div style="flex-wrap: wrap">
    <toggle class="margin" for="{{toggle_list}}" id="{{$item.id}}" checked="{{$item.checked}}" 
      value="{{$item.name}}" @change="allchange" @click="allclick({{$item.id}})"></toggle>
  </div>
</div>
```

```
/* xxx.css */
.margin {
  margin: 7px;
}
```

```
// xxx.js
export default {
  data: {
    toggle_list: [
      { "id":"1001", "name":"Living room", "checked":true },
      { "id":"1002", "name":"Bedroom", "checked":false },
      { "id":"1003", "name":"Second bedroom", "checked":false },
      { "id":"1004", "name":"Kitchen", "checked":false },
      { "id":"1005", "name":"Study", "checked":false },
      { "id":"1006", "name":"Garden", "checked":false },
      { "id":"1007", "name":"Bathroom", "checked":false },
      { "id":"1008", "name":"Balcony", "checked":false },
    ],
    toggles: ["Living room","Bedroom","Kitchen","Study"],
    idx: ""
  },
  allclick(arg) {
    this.idx = arg
  },
  allchange(e) {
    if (e.checked === true) {
      for (var i = 0; i < this.toggle_list.length; i++) {
        if (this.toggle_list[i].id === this.idx) {
          this.toggle_list[i].checked = true
        } else {
          this.toggle_list[i].checked = false
        }
      }
    }
  }
}
```

![](figures/screenshot.png)

