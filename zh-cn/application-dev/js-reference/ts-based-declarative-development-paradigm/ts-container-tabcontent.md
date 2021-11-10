# TabContent<a name="ZH-CN_TOPIC_0000001119929128"></a>

仅在Tabs中使用，对应一个切换页签的内容视图。

## 权限列表<a name="section988262631714"></a>

无

## 子组件<a name="section5989144051714"></a>

支持单个子组件。

## 接口<a name="section97451749121712"></a>

TabContent\(\)

## 属性<a name="section1738516911810"></a>

<a name="table1854mcpsimp"></a>
<table><thead align="left"><tr id="row1861mcpsimp"><th class="cellrowborder" valign="top" width="8.84%" id="mcps1.1.5.1.1"><p id="p1863mcpsimp"><a name="p1863mcpsimp"></a><a name="p1863mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="24.82%" id="mcps1.1.5.1.2"><p id="p1865mcpsimp"><a name="p1865mcpsimp"></a><a name="p1865mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.88%" id="mcps1.1.5.1.3"><p id="p1867mcpsimp"><a name="p1867mcpsimp"></a><a name="p1867mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="54.459999999999994%" id="mcps1.1.5.1.4"><p id="p1869mcpsimp"><a name="p1869mcpsimp"></a><a name="p1869mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1870mcpsimp"><td class="cellrowborder" valign="top" width="8.84%" headers="mcps1.1.5.1.1 "><p id="p10682mcpsimp"><a name="p10682mcpsimp"></a><a name="p10682mcpsimp"></a>tabBar</p>
</td>
<td class="cellrowborder" valign="top" width="24.82%" headers="mcps1.1.5.1.2 "><p id="p183331827143515"><a name="p183331827143515"></a><a name="p183331827143515"></a>string | {</p>
<p id="p6774182313515"><a name="p6774182313515"></a><a name="p6774182313515"></a>icon?: string,</p>
<p id="p7318830153513"><a name="p7318830153513"></a><a name="p7318830153513"></a>text?: string</p>
<p id="p10684mcpsimp"><a name="p10684mcpsimp"></a><a name="p10684mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="11.88%" headers="mcps1.1.5.1.3 "><p id="p10686mcpsimp"><a name="p10686mcpsimp"></a><a name="p10686mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.1.5.1.4 "><p id="p10688mcpsimp"><a name="p10688mcpsimp"></a><a name="p10688mcpsimp"></a>设置TabBar上显示内容。</p>
<div class="note" id="note66251557181812"><a name="note66251557181812"></a><a name="note66251557181812"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p6625125761813"><a name="p6625125761813"></a><a name="p6625125761813"></a>如果icon采用svg格式图源，则要求svg图源删除其自有宽高属性值。如采用带有自有宽高属性的svg图源，icon大小则是svg本身内置的宽高属性值大小。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   TabContent组件不支持设置通用宽度属性，其宽度默认撑满Tabs父组件。
>-   TabContent组件不支持设置通用高度属性，其高度由Tabs父组件高度与TabBar组件高度决定。

## 示例<a name="section1131255321814"></a>

见[Tabs](ts-container-tabs.md#section1131255321814)。

