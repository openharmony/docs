# OHOS::Window<a name="EN-US_TOPIC_0000001055678106"></a>

-   [Overview](#section1231891241165632)
-   [Summary](#section39354735165632)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section1231891241165632"></a>

**Related Modules:**

[Window](window.md)

**Description:**

Provides a drawing canvas for the  **[RootView](ohos-rootview.md)**, which represents the root node of a view tree. 

Each window is bound to a  **[RootView](ohos-rootview.md)**. For details, see  [RootView](ohos-rootview.md). This class also provides window management capabilities, including creating, destroying, showing, hiding, moving, resizing a window, raising a window to the top, and lowering a window to the bottom.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section39354735165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table919751684165632"></a>
<table><thead align="left"><tr id="row341997034165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1499170781165632"><a name="p1499170781165632"></a><a name="p1499170781165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p366062207165632"><a name="p366062207165632"></a><a name="p366062207165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1078211586165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1164037953165632"><a name="p1164037953165632"></a><a name="p1164037953165632"></a><a href="window.md#ga10d20114dbd02b0ea8306fd508108af9">BindRootView</a> (<a href="ohos-rootview.md">RootView</a> *rootView)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122619147165632"><a name="p122619147165632"></a><a name="p122619147165632"></a>virtual void </p>
<p id="p425083211165632"><a name="p425083211165632"></a><a name="p425083211165632"></a>Binds the <strong id="b1290655900165632"><a name="b1290655900165632"></a><a name="b1290655900165632"></a><a href="ohos-rootview.md">RootView</a></strong> to this window. </p>
</td>
</tr>
<tr id="row2062151201165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1800063191165632"><a name="p1800063191165632"></a><a name="p1800063191165632"></a><a href="window.md#ga7ad1bbc5a9a758e48a0fcecc10512bf2">UnbindRootView</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755696927165632"><a name="p1755696927165632"></a><a name="p1755696927165632"></a>virtual void </p>
<p id="p1351372736165632"><a name="p1351372736165632"></a><a name="p1351372736165632"></a>Unbinds the <strong id="b2140366014165632"><a name="b2140366014165632"></a><a name="b2140366014165632"></a><a href="ohos-rootview.md">RootView</a></strong> from this window. </p>
</td>
</tr>
<tr id="row1746578215165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606590746165632"><a name="p1606590746165632"></a><a name="p1606590746165632"></a><a href="window.md#ga0f81825ac2f7acd742d114627d007dc0">GetRootView</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1692483431165632"><a name="p1692483431165632"></a><a name="p1692483431165632"></a>virtual <a href="ohos-rootview.md">RootView</a> * </p>
<p id="p726679992165632"><a name="p726679992165632"></a><a name="p726679992165632"></a>Obtains the <strong id="b304177807165632"><a name="b304177807165632"></a><a name="b304177807165632"></a><a href="ohos-rootview.md">RootView</a></strong> bound to this window. </p>
</td>
</tr>
<tr id="row729721263165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p606170637165632"><a name="p606170637165632"></a><a name="p606170637165632"></a><a href="window.md#ga2c14344eed608ec8cd345a6c1c835a53">GetRect</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p892446256165632"><a name="p892446256165632"></a><a name="p892446256165632"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1443475930165632"><a name="p1443475930165632"></a><a name="p1443475930165632"></a>Obtains the rectangle information (position, width, and height) of this window. </p>
</td>
</tr>
<tr id="row137540718165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p127977615165632"><a name="p127977615165632"></a><a name="p127977615165632"></a><a href="window.md#ga920aaa7deb0054c1436b2aaba3a81e4f">Show</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1951711105165632"><a name="p1951711105165632"></a><a name="p1951711105165632"></a>virtual void </p>
<p id="p1847624624165632"><a name="p1847624624165632"></a><a name="p1847624624165632"></a>Shows this window. </p>
</td>
</tr>
<tr id="row469749992165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p538090701165632"><a name="p538090701165632"></a><a name="p538090701165632"></a><a href="window.md#ga37272c50d164a77bf004c18174d94736">Hide</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383949027165632"><a name="p1383949027165632"></a><a name="p1383949027165632"></a>virtual void </p>
<p id="p1774003999165632"><a name="p1774003999165632"></a><a name="p1774003999165632"></a>Hides this window. </p>
</td>
</tr>
<tr id="row1829430601165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425637462165632"><a name="p425637462165632"></a><a name="p425637462165632"></a><a href="window.md#ga7454cb1c3c28e68f4e962fef108a0d2f">MoveTo</a> (int16_t x, int16_t y)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p625322612165632"><a name="p625322612165632"></a><a name="p625322612165632"></a>virtual void </p>
<p id="p1725431527165632"><a name="p1725431527165632"></a><a name="p1725431527165632"></a>Moves this window to a specified position. </p>
</td>
</tr>
<tr id="row526163747165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p342794497165632"><a name="p342794497165632"></a><a name="p342794497165632"></a><a href="window.md#gac2c1bf9dc681741eb9c0490785bd73c2">Resize</a> (int16_t width, int16_t height)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2078301534165632"><a name="p2078301534165632"></a><a name="p2078301534165632"></a>virtual void </p>
<p id="p690283230165632"><a name="p690283230165632"></a><a name="p690283230165632"></a>Resizes this window. </p>
</td>
</tr>
<tr id="row1458886934165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676027621165632"><a name="p1676027621165632"></a><a name="p1676027621165632"></a><a href="window.md#ga395aa07d4a622059c627d18ecd2ff115">RaiseToTop</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1918431242165632"><a name="p1918431242165632"></a><a name="p1918431242165632"></a>virtual void </p>
<p id="p325910730165632"><a name="p325910730165632"></a><a name="p325910730165632"></a>Raises this window to the top. </p>
</td>
</tr>
<tr id="row54320511165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1532367859165632"><a name="p1532367859165632"></a><a name="p1532367859165632"></a><a href="window.md#ga61c01a10b37843abf8cf348bd7d1d659">LowerToBottom</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p993181383165632"><a name="p993181383165632"></a><a name="p993181383165632"></a>virtual void </p>
<p id="p179841609165632"><a name="p179841609165632"></a><a name="p179841609165632"></a>Lowers this window to the bottom. </p>
</td>
</tr>
<tr id="row1510226495165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p261561999165632"><a name="p261561999165632"></a><a name="p261561999165632"></a><a href="window.md#ga7efafa2bc07e9a0b5fc5c4c8b1b17b89">GetWindowId</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1909443599165632"><a name="p1909443599165632"></a><a name="p1909443599165632"></a>virtual int32_t </p>
<p id="p998805443165632"><a name="p998805443165632"></a><a name="p998805443165632"></a>Obtains the unique ID of this window. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table169897189165632"></a>
<table><thead align="left"><tr id="row1412835999165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p997921220165632"><a name="p997921220165632"></a><a name="p997921220165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p266696082165632"><a name="p266696082165632"></a><a name="p266696082165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row882970874165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1632249843165632"><a name="p1632249843165632"></a><a name="p1632249843165632"></a><a href="window.md#ga13f51542db51b560e4bd8c52fe37a7d0">CreateWindow</a> (const <a href="ohos-windowconfig.md">WindowConfig</a> &amp;config)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1435975212165632"><a name="p1435975212165632"></a><a name="p1435975212165632"></a>static <a href="ohos-window.md">Window</a> * </p>
<p id="p1105738187165632"><a name="p1105738187165632"></a><a name="p1105738187165632"></a>Creates a <strong id="b1310471102165632"><a name="b1310471102165632"></a><a name="b1310471102165632"></a><a href="ohos-window.md">Window</a></strong> instance. </p>
</td>
</tr>
<tr id="row1968934552165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1199040221165632"><a name="p1199040221165632"></a><a name="p1199040221165632"></a><a href="window.md#gaae86fd5bd45c654159939ac4ba877cc1">DestoryWindow</a> (<a href="ohos-window.md">Window</a> *window)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064927603165632"><a name="p2064927603165632"></a><a name="p2064927603165632"></a>static void </p>
<p id="p1321545666165632"><a name="p1321545666165632"></a><a name="p1321545666165632"></a>Destroys a specified window. </p>
</td>
</tr>
</tbody>
</table>

