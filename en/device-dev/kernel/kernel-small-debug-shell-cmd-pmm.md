# pmm<a name="EN-US_TOPIC_0000001179965839"></a>

-   [Command Function](#section445335110416)
-   [Syntax](#section1795712553416)
-   [Parameters](#section92544592410)
-   [Usage](#section104151141252)
-   [Example](#section11545171957)
-   [Output](#section075617368542)

## Command Function<a name="section445335110416"></a>

This command is used to check the usage of the physical pages and page cache of the system memory.

## Syntax<a name="section1795712553416"></a>

pmm

## Parameters<a name="section92544592410"></a>

None

## Usage<a name="section104151141252"></a>

This command is available only in the  **Debug**  version.

## Example<a name="section11545171957"></a>

Run  **pmm**.

## Output<a name="section075617368542"></a>

**Figure  1**  Viewing the usage of physical pages<a name="fig19209202618618"></a>  
![](figure/viewing-the-usage-of-physical-pages.png "viewing-the-usage-of-physical-pages")

**Table  1**  Output

<a name="table5579102611579"></a>
<table><thead align="left"><tr id="row12579162613572"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p18579122619578"><a name="p18579122619578"></a><a name="p18579122619578"></a>Output</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p11579182635718"><a name="p11579182635718"></a><a name="p11579182635718"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1457942675720"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2058042605713"><a name="p2058042605713"></a><a name="p2058042605713"></a>phys_seg</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1058062614579"><a name="p1058062614579"></a><a name="p1058062614579"></a>Address of the physical page control block</p>
</td>
</tr>
<tr id="row14580192616575"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p858062615712"><a name="p858062615712"></a><a name="p858062615712"></a>base</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1858082617577"><a name="p1858082617577"></a><a name="p1858082617577"></a>First physical page address, that is, start address of the physical page memory</p>
</td>
</tr>
<tr id="row17580826115719"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p5580226155713"><a name="p5580226155713"></a><a name="p5580226155713"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p85808262572"><a name="p85808262572"></a><a name="p85808262572"></a>Size of the physical page memory</p>
</td>
</tr>
<tr id="row161931831175912"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p201931631185913"><a name="p201931631185913"></a><a name="p201931631185913"></a>free_pages</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1919383125911"><a name="p1919383125911"></a><a name="p1919383125911"></a>Number of free physical pages</p>
</td>
</tr>
<tr id="row1397105119596"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p0397951175918"><a name="p0397951175918"></a><a name="p0397951175918"></a>active anon</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1139715117599"><a name="p1139715117599"></a><a name="p1139715117599"></a>Number of active anonymous pages in the page cache</p>
</td>
</tr>
<tr id="row16409173520010"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p941012351409"><a name="p941012351409"></a><a name="p941012351409"></a>inactive anon</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1341012355019"><a name="p1341012355019"></a><a name="p1341012355019"></a>Number of inactive anonymous pages in the page cache</p>
</td>
</tr>
<tr id="row467016386014"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10670103818015"><a name="p10670103818015"></a><a name="p10670103818015"></a>active file</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1267012382019"><a name="p1267012382019"></a><a name="p1267012382019"></a>Number of active file pages in the page cache</p>
</td>
</tr>
<tr id="row18966641507"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p5966741706"><a name="p5966741706"></a><a name="p5966741706"></a>inactive file</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17966174115018"><a name="p17966174115018"></a><a name="p17966174115018"></a>Number of inactive file pages in the page cache</p>
</td>
</tr>
<tr id="row13183445101"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p318394514018"><a name="p318394514018"></a><a name="p318394514018"></a>pmm pages</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1616375952018"><a name="p1616375952018"></a><a name="p1616375952018"></a><strong id="b161631659162014"><a name="b161631659162014"></a><a name="b161631659162014"></a>total</strong>: indicates the total number of physical pages. </p>
<p id="p2029802122113"><a name="p2029802122113"></a><a name="p2029802122113"></a><strong id="b429822122113"><a name="b429822122113"></a><a name="b429822122113"></a>used</strong>: indicates the number of used physical pages. </p>
<p id="p1218312452014"><a name="p1218312452014"></a><a name="p1218312452014"></a><strong id="b132798755433826"><a name="b132798755433826"></a><a name="b132798755433826"></a>free</strong>: indicates the number of free physical pages.</p>
</td>
</tr>
</tbody>
</table>

