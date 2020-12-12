# window.h<a name="EN-US_TOPIC_0000001055039504"></a>

-   [Overview](#section1959510349165630)
-   [Summary](#section1576124703165630)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)

## **Overview**<a name="section1959510349165630"></a>

**Related Modules:**

[Window](window.md)

**Description:**

Declares the  **Window**  class that provides a drawing canvas for the  **RootView**, which represents the root node of a view tree. 

Each window is bound to a  **RootView**. For details, see  **RootView**. The  **Window**  class also provides window management capabilities, including creating, destroying, showing, hiding, moving, resizing a window, raising a window to the top, and lowering a window to the bottom.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1576124703165630"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table80205804165630"></a>
<table><thead align="left"><tr id="row299334430165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1713715819165630"><a name="p1713715819165630"></a><a name="p1713715819165630"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1297962693165630"><a name="p1297962693165630"></a><a name="p1297962693165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row79591548165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p124368314165630"><a name="p124368314165630"></a><a name="p124368314165630"></a><a href="ohos-windowconfig.md">OHOS::WindowConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735697729165630"><a name="p735697729165630"></a><a name="p735697729165630"></a>Sets the attributes for this window. </p>
</td>
</tr>
<tr id="row201259113165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p882935758165630"><a name="p882935758165630"></a><a name="p882935758165630"></a><a href="ohos-window.md">OHOS::Window</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p382787913165630"><a name="p382787913165630"></a><a name="p382787913165630"></a>Provides a drawing canvas for the <strong id="b1714869242165630"><a name="b1714869242165630"></a><a name="b1714869242165630"></a><a href="ohos-rootview.md">RootView</a></strong>, which represents the root node of a view tree. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1569673170165630"></a>
<table><thead align="left"><tr id="row1731278930165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p916873233165630"><a name="p916873233165630"></a><a name="p916873233165630"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p374031474165630"><a name="p374031474165630"></a><a name="p374031474165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row388788249165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141653857165630"><a name="p141653857165630"></a><a name="p141653857165630"></a><a href="window.md#gade9f6a70c1e8547785d266aab3ca5725">OHOS::WindowPixelFormat</a> { <a href="window.md#ggade9f6a70c1e8547785d266aab3ca5725a23fea82a04292ba974dad96468ae610c">OHOS::WINDOW_PIXEL_FORMAT_RGB565</a> = 101, <a href="window.md#ggade9f6a70c1e8547785d266aab3ca5725a4f397aa8d8480b22b8a65594e09fbc9a">OHOS::WINDOW_PIXEL_FORMAT_ARGB1555</a>, <a href="window.md#ggade9f6a70c1e8547785d266aab3ca5725a083e4a4abba5810d7bedb8a65bea23f1">OHOS::WINDOW_PIXEL_FORMAT_RGB888</a>, <a href="window.md#ggade9f6a70c1e8547785d266aab3ca5725a94212b4cc96d2cb46cec7de114437d26">OHOS::WINDOW_PIXEL_FORMAT_ARGB8888</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1252244227165630"><a name="p1252244227165630"></a><a name="p1252244227165630"></a>Enumerates the pixel formats of this window. </p>
</td>
</tr>
</tbody>
</table>

