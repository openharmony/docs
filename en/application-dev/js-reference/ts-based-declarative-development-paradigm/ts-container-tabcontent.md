# TabContent<a name="EN-US_TOPIC_0000001119929128"></a>

The  **<TabContent\>**  component is used only in the  **<Tabs\>**  component. It corresponds to the content view of a switched tab page.

## Required Permissions<a name="section988262631714"></a>

None

## Child Component<a name="section5989144051714"></a>

This component supports only one child component.

## APIs<a name="section97451749121712"></a>

TabContent\(\)

## Attributes<a name="section1738516911810"></a>

<a name="table1854mcpsimp"></a>
<table><thead align="left"><tr id="row1861mcpsimp"><th class="cellrowborder" valign="top" width="8.84%" id="mcps1.1.5.1.1"><p id="p1863mcpsimp"><a name="p1863mcpsimp"></a><a name="p1863mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.82%" id="mcps1.1.5.1.2"><p id="p1865mcpsimp"><a name="p1865mcpsimp"></a><a name="p1865mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.88%" id="mcps1.1.5.1.3"><p id="p1867mcpsimp"><a name="p1867mcpsimp"></a><a name="p1867mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="54.459999999999994%" id="mcps1.1.5.1.4"><p id="p1869mcpsimp"><a name="p1869mcpsimp"></a><a name="p1869mcpsimp"></a>Description</p>
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
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.1.5.1.4 "><p id="p10688mcpsimp"><a name="p10688mcpsimp"></a><a name="p10688mcpsimp"></a>Content displayed on the tab bar.</p>
<div class="note" id="note66251557181812"><a name="note66251557181812"></a><a name="note66251557181812"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p6625125761813"><a name="p6625125761813"></a><a name="p6625125761813"></a>If an icon uses an SVG image, the width and height attributes of the SVG image must be deleted. Otherwise, the icon size will be determined by the width and height attributes of the SVG image.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **<TabContent\>**  component does not support setting of the common width attribute. By default, its width is the same as that of the parent  **<Tabs\>**  component.
>-   The  **<TabContent\>**  component does not support setting of the common height attribute. Its height is determined by the height of the parent  **<Tabs\>**  component and the  **<TabBar\>**  component.

## Example<a name="section1131255321814"></a>

See  [Tabs](ts-container-tabs.md#section1131255321814).

