# Window<a name="ZH-CN_TOPIC_0000001055039468"></a>

-   [Overview](#section75228680165625)
-   [Summary](#section1987360514165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1328341200165625)
-   [Enumeration Type](#section1779893936165625)
-   [WindowPixelFormat](#gade9f6a70c1e8547785d266aab3ca5725)
-   [Function](#section536210334165625)
-   [BindRootView\(\)](#ga10d20114dbd02b0ea8306fd508108af9)
-   [CreateWindow\(\)](#ga13f51542db51b560e4bd8c52fe37a7d0)
-   [DestoryWindow\(\)](#gaae86fd5bd45c654159939ac4ba877cc1)
-   [GetRect\(\)](#ga2c14344eed608ec8cd345a6c1c835a53)
-   [GetRootView\(\)](#ga0f81825ac2f7acd742d114627d007dc0)
-   [GetWindowId\(\)](#ga7efafa2bc07e9a0b5fc5c4c8b1b17b89)
-   [Hide\(\)](#ga37272c50d164a77bf004c18174d94736)
-   [LowerToBottom\(\)](#ga61c01a10b37843abf8cf348bd7d1d659)
-   [MoveTo\(\)](#ga7454cb1c3c28e68f4e962fef108a0d2f)
-   [RaiseToTop\(\)](#ga395aa07d4a622059c627d18ecd2ff115)
-   [Resize\(\)](#gac2c1bf9dc681741eb9c0490785bd73c2)
-   [Show\(\)](#ga920aaa7deb0054c1436b2aaba3a81e4f)
-   [UnbindRootView\(\)](#ga7ad1bbc5a9a758e48a0fcecc10512bf2)
-   [Variable](#section1566951119165625)
-   [opacity](#ga848d59949e340c4c2572c49212eb6f5a)
-   [option](#gae5bf33ab2eecd5dcafe2eb3da43d6f27)
-   [pixelFormat](#ga213fd5a52a7232dd4fbaef7108e2a36a)
-   [rect](#gabb7c9c7f86fb9f1d29728ca0afa10668)

## **Overview**<a name="section75228680165625"></a>

**Description:**

Provides window management capabilities, including creating, destroying, showing, hiding, moving, resizing a window, raising a window to the top, and lowering a window to the bottom. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1987360514165625"></a>

## Files<a name="files"></a>

<a name="table627616259165625"></a>
<table><thead align="left"><tr id="row1389323595165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p648449029165625"><a name="p648449029165625"></a><a name="p648449029165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2020360829165625"><a name="p2020360829165625"></a><a name="p2020360829165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row622170652165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p345843185165625"><a name="p345843185165625"></a><a name="p345843185165625"></a><a href="window-h.md">window.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p415768689165625"><a name="p415768689165625"></a><a name="p415768689165625"></a>Declares the <strong id="b1992295672165625"><a name="b1992295672165625"></a><a name="b1992295672165625"></a>Window</strong> class that provides a drawing canvas for the <strong id="b1409388542165625"><a name="b1409388542165625"></a><a name="b1409388542165625"></a>RootView</strong>, which represents the root node of a view tree. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1775490007165625"></a>
<table><thead align="left"><tr id="row1581773751165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1024385086165625"><a name="p1024385086165625"></a><a name="p1024385086165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2016868566165625"><a name="p2016868566165625"></a><a name="p2016868566165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row256104080165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1843747599165625"><a name="p1843747599165625"></a><a name="p1843747599165625"></a><a href="OHOS-WindowConfig.md">OHOS::WindowConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624337289165625"><a name="p624337289165625"></a><a name="p624337289165625"></a>Sets the attributes for this window. </p>
</td>
</tr>
<tr id="row19532416165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383015349165625"><a name="p383015349165625"></a><a name="p383015349165625"></a><a href="OHOS-Window.md">OHOS::Window</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1568423940165625"><a name="p1568423940165625"></a><a name="p1568423940165625"></a>Provides a drawing canvas for the <strong id="b1998030631165625"><a name="b1998030631165625"></a><a name="b1998030631165625"></a><a href="OHOS-RootView.md">RootView</a></strong>, which represents the root node of a view tree. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1903593032165625"></a>
<table><thead align="left"><tr id="row964334868165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2030292924165625"><a name="p2030292924165625"></a><a name="p2030292924165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1032129401165625"><a name="p1032129401165625"></a><a name="p1032129401165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1216082844165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1711150920165625"><a name="p1711150920165625"></a><a name="p1711150920165625"></a><a href="Window.md#gade9f6a70c1e8547785d266aab3ca5725">OHOS::WindowPixelFormat</a> { <a href="Window.md#ggade9f6a70c1e8547785d266aab3ca5725a23fea82a04292ba974dad96468ae610c">OHOS::WINDOW_PIXEL_FORMAT_RGB565</a> = 101, <a href="Window.md#ggade9f6a70c1e8547785d266aab3ca5725a4f397aa8d8480b22b8a65594e09fbc9a">OHOS::WINDOW_PIXEL_FORMAT_ARGB1555</a>, <a href="Window.md#ggade9f6a70c1e8547785d266aab3ca5725a083e4a4abba5810d7bedb8a65bea23f1">OHOS::WINDOW_PIXEL_FORMAT_RGB888</a>, <a href="Window.md#ggade9f6a70c1e8547785d266aab3ca5725a94212b4cc96d2cb46cec7de114437d26">OHOS::WINDOW_PIXEL_FORMAT_ARGB8888</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p374443233165625"><a name="p374443233165625"></a><a name="p374443233165625"></a>Enumerates the pixel formats of this window. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1668349453165625"></a>
<table><thead align="left"><tr id="row1666507335165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p619882020165625"><a name="p619882020165625"></a><a name="p619882020165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p412796785165625"><a name="p412796785165625"></a><a name="p412796785165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2040043150165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526498876165625"><a name="p1526498876165625"></a><a name="p1526498876165625"></a><a href="Window.md#ga13f51542db51b560e4bd8c52fe37a7d0">OHOS::Window::CreateWindow</a> (const <a href="OHOS-WindowConfig.md">WindowConfig</a> &amp;config)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719971176165625"><a name="p1719971176165625"></a><a name="p1719971176165625"></a>static <a href="OHOS-Window.md">Window</a> * </p>
<p id="p1875079564165625"><a name="p1875079564165625"></a><a name="p1875079564165625"></a>Creates a <strong id="b1515532938165625"><a name="b1515532938165625"></a><a name="b1515532938165625"></a><a href="OHOS-Window.md">Window</a></strong> instance. </p>
</td>
</tr>
<tr id="row1553689411165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1918547203165625"><a name="p1918547203165625"></a><a name="p1918547203165625"></a><a href="Window.md#gaae86fd5bd45c654159939ac4ba877cc1">OHOS::Window::DestoryWindow</a> (<a href="OHOS-Window.md">Window</a> *window)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1749474695165625"><a name="p1749474695165625"></a><a name="p1749474695165625"></a>static void </p>
<p id="p434283845165625"><a name="p434283845165625"></a><a name="p434283845165625"></a>Destroys a specified window. </p>
</td>
</tr>
<tr id="row636014220165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p884285315165625"><a name="p884285315165625"></a><a name="p884285315165625"></a><a href="Window.md#ga10d20114dbd02b0ea8306fd508108af9">OHOS::Window::BindRootView</a> (<a href="OHOS-RootView.md">RootView</a> *rootView)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1249055273165625"><a name="p1249055273165625"></a><a name="p1249055273165625"></a>virtual void </p>
<p id="p113154054165625"><a name="p113154054165625"></a><a name="p113154054165625"></a>Binds the <strong id="b577276369165625"><a name="b577276369165625"></a><a name="b577276369165625"></a><a href="OHOS-RootView.md">RootView</a></strong> to this window. </p>
</td>
</tr>
<tr id="row88439806165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p289980841165625"><a name="p289980841165625"></a><a name="p289980841165625"></a><a href="Window.md#ga7ad1bbc5a9a758e48a0fcecc10512bf2">OHOS::Window::UnbindRootView</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166727989165625"><a name="p166727989165625"></a><a name="p166727989165625"></a>virtual void </p>
<p id="p983427903165625"><a name="p983427903165625"></a><a name="p983427903165625"></a>Unbinds the <strong id="b606080830165625"><a name="b606080830165625"></a><a name="b606080830165625"></a><a href="OHOS-RootView.md">RootView</a></strong> from this window. </p>
</td>
</tr>
<tr id="row759351714165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1984308229165625"><a name="p1984308229165625"></a><a name="p1984308229165625"></a><a href="Window.md#ga0f81825ac2f7acd742d114627d007dc0">OHOS::Window::GetRootView</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1509693672165625"><a name="p1509693672165625"></a><a name="p1509693672165625"></a>virtual <a href="OHOS-RootView.md">RootView</a> * </p>
<p id="p925319960165625"><a name="p925319960165625"></a><a name="p925319960165625"></a>Obtains the <strong id="b122556853165625"><a name="b122556853165625"></a><a name="b122556853165625"></a><a href="OHOS-RootView.md">RootView</a></strong> bound to this window. </p>
</td>
</tr>
<tr id="row1910964537165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1769367717165625"><a name="p1769367717165625"></a><a name="p1769367717165625"></a><a href="Window.md#ga2c14344eed608ec8cd345a6c1c835a53">OHOS::Window::GetRect</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637636758165625"><a name="p637636758165625"></a><a name="p637636758165625"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p770372915165625"><a name="p770372915165625"></a><a name="p770372915165625"></a>Obtains the rectangle information (position, width, and height) of this window. </p>
</td>
</tr>
<tr id="row1943150806165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626155563165625"><a name="p1626155563165625"></a><a name="p1626155563165625"></a><a href="Window.md#ga920aaa7deb0054c1436b2aaba3a81e4f">OHOS::Window::Show</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1788368141165625"><a name="p1788368141165625"></a><a name="p1788368141165625"></a>virtual void </p>
<p id="p1759098324165625"><a name="p1759098324165625"></a><a name="p1759098324165625"></a>Shows this window. </p>
</td>
</tr>
<tr id="row1856466014165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368669120165625"><a name="p368669120165625"></a><a name="p368669120165625"></a><a href="Window.md#ga37272c50d164a77bf004c18174d94736">OHOS::Window::Hide</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447588157165625"><a name="p1447588157165625"></a><a name="p1447588157165625"></a>virtual void </p>
<p id="p1675545192165625"><a name="p1675545192165625"></a><a name="p1675545192165625"></a>Hides this window. </p>
</td>
</tr>
<tr id="row521061235165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1017386548165625"><a name="p1017386548165625"></a><a name="p1017386548165625"></a><a href="Window.md#ga7454cb1c3c28e68f4e962fef108a0d2f">OHOS::Window::MoveTo</a> (int16_t x, int16_t y)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p524848828165625"><a name="p524848828165625"></a><a name="p524848828165625"></a>virtual void </p>
<p id="p1114838809165625"><a name="p1114838809165625"></a><a name="p1114838809165625"></a>Moves this window to a specified position. </p>
</td>
</tr>
<tr id="row1599597140165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1818666491165625"><a name="p1818666491165625"></a><a name="p1818666491165625"></a><a href="Window.md#gac2c1bf9dc681741eb9c0490785bd73c2">OHOS::Window::Resize</a> (int16_t width, int16_t height)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19315554165625"><a name="p19315554165625"></a><a name="p19315554165625"></a>virtual void </p>
<p id="p298497009165625"><a name="p298497009165625"></a><a name="p298497009165625"></a>Resizes this window. </p>
</td>
</tr>
<tr id="row1907980310165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964039944165625"><a name="p964039944165625"></a><a name="p964039944165625"></a><a href="Window.md#ga395aa07d4a622059c627d18ecd2ff115">OHOS::Window::RaiseToTop</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2048604860165625"><a name="p2048604860165625"></a><a name="p2048604860165625"></a>virtual void </p>
<p id="p772365877165625"><a name="p772365877165625"></a><a name="p772365877165625"></a>Raises this window to the top. </p>
</td>
</tr>
<tr id="row958683719165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1919962232165625"><a name="p1919962232165625"></a><a name="p1919962232165625"></a><a href="Window.md#ga61c01a10b37843abf8cf348bd7d1d659">OHOS::Window::LowerToBottom</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p214597075165625"><a name="p214597075165625"></a><a name="p214597075165625"></a>virtual void </p>
<p id="p607678320165625"><a name="p607678320165625"></a><a name="p607678320165625"></a>Lowers this window to the bottom. </p>
</td>
</tr>
<tr id="row2034822171165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p557871083165625"><a name="p557871083165625"></a><a name="p557871083165625"></a><a href="Window.md#ga7efafa2bc07e9a0b5fc5c4c8b1b17b89">OHOS::Window::GetWindowId</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734465647165625"><a name="p1734465647165625"></a><a name="p1734465647165625"></a>virtual int32_t </p>
<p id="p1310760842165625"><a name="p1310760842165625"></a><a name="p1310760842165625"></a>Obtains the unique ID of this window. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1328341200165625"></a>

## **Enumeration Type **<a name="section1779893936165625"></a>

## WindowPixelFormat<a name="gade9f6a70c1e8547785d266aab3ca5725"></a>

```
enum [OHOS::WindowPixelFormat](Window.md#gade9f6a70c1e8547785d266aab3ca5725)
```

 **Description:**

Enumerates the pixel formats of this window. 

<a name="table528043672165625"></a>
<table><thead align="left"><tr id="row1521467821165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p157100615165625"><a name="p157100615165625"></a><a name="p157100615165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1277327174165625"><a name="p1277327174165625"></a><a name="p1277327174165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row954639093165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggade9f6a70c1e8547785d266aab3ca5725a23fea82a04292ba974dad96468ae610c"><a name="ggade9f6a70c1e8547785d266aab3ca5725a23fea82a04292ba974dad96468ae610c"></a><a name="ggade9f6a70c1e8547785d266aab3ca5725a23fea82a04292ba974dad96468ae610c"></a></strong>WINDOW_PIXEL_FORMAT_RGB565 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p70677017165625"><a name="p70677017165625"></a><a name="p70677017165625"></a>RGB565 format </p>
 </td>
</tr>
<tr id="row1909481051165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggade9f6a70c1e8547785d266aab3ca5725a4f397aa8d8480b22b8a65594e09fbc9a"><a name="ggade9f6a70c1e8547785d266aab3ca5725a4f397aa8d8480b22b8a65594e09fbc9a"></a><a name="ggade9f6a70c1e8547785d266aab3ca5725a4f397aa8d8480b22b8a65594e09fbc9a"></a></strong>WINDOW_PIXEL_FORMAT_ARGB1555 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p21980419165625"><a name="p21980419165625"></a><a name="p21980419165625"></a>ARGB1555 format </p>
 </td>
</tr>
<tr id="row159447522165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggade9f6a70c1e8547785d266aab3ca5725a083e4a4abba5810d7bedb8a65bea23f1"><a name="ggade9f6a70c1e8547785d266aab3ca5725a083e4a4abba5810d7bedb8a65bea23f1"></a><a name="ggade9f6a70c1e8547785d266aab3ca5725a083e4a4abba5810d7bedb8a65bea23f1"></a></strong>WINDOW_PIXEL_FORMAT_RGB888 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1271962337165625"><a name="p1271962337165625"></a><a name="p1271962337165625"></a>RGB888 format </p>
 </td>
</tr>
<tr id="row886093831165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggade9f6a70c1e8547785d266aab3ca5725a94212b4cc96d2cb46cec7de114437d26"><a name="ggade9f6a70c1e8547785d266aab3ca5725a94212b4cc96d2cb46cec7de114437d26"></a><a name="ggade9f6a70c1e8547785d266aab3ca5725a94212b4cc96d2cb46cec7de114437d26"></a></strong>WINDOW_PIXEL_FORMAT_ARGB8888 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1878214793165625"><a name="p1878214793165625"></a><a name="p1878214793165625"></a>ARGB8888 format </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section536210334165625"></a>

## BindRootView\(\)<a name="ga10d20114dbd02b0ea8306fd508108af9"></a>

```
virtual void OHOS::Window::BindRootView ([RootView](OHOS-RootView.md) * rootView)
```

 **Description:**

Binds the  **[RootView](OHOS-RootView.md)**  to this window. 

**Parameters:**

<a name="table982421367165625"></a>
<table><thead align="left"><tr id="row979775697165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1161078478165625"><a name="p1161078478165625"></a><a name="p1161078478165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p899128864165625"><a name="p899128864165625"></a><a name="p899128864165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row74413625165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rootView</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b614296560165625"><a name="b614296560165625"></a><a name="b614296560165625"></a><a href="OHOS-RootView.md">RootView</a></strong> to bind. </td>
</tr>
</tbody>
</table>

## CreateWindow\(\)<a name="ga13f51542db51b560e4bd8c52fe37a7d0"></a>

```
static [Window](OHOS-Window.md)* OHOS::Window::CreateWindow (const [WindowConfig](OHOS-WindowConfig.md) & config)
```

 **Description:**

Creates a  **[Window](OHOS-Window.md)**  instance. 

**Parameters:**

<a name="table172877898165625"></a>
<table><thead align="left"><tr id="row724721530165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1346524942165625"><a name="p1346524942165625"></a><a name="p1346524942165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p589466888165625"><a name="p589466888165625"></a><a name="p589466888165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1511358453165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">config</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the window configuration. For details, see <a href="OHOS-WindowConfig.md">WindowConfig</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the  **[Window](OHOS-Window.md)**  instance if the operation is successful; returns  **nullptr**  otherwise. 

## DestoryWindow\(\)<a name="gaae86fd5bd45c654159939ac4ba877cc1"></a>

```
static void OHOS::Window::DestoryWindow ([Window](OHOS-Window.md) * window)
```

 **Description:**

Destroys a specified window. 

**Parameters:**

<a name="table189548465165625"></a>
<table><thead align="left"><tr id="row2039755818165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p749453091165625"><a name="p749453091165625"></a><a name="p749453091165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p678492353165625"><a name="p678492353165625"></a><a name="p678492353165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1806895536165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">window</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b312551385165625"><a name="b312551385165625"></a><a name="b312551385165625"></a><a href="OHOS-Window.md">Window</a></strong> instance to destroy. </td>
</tr>
</tbody>
</table>

## GetRect\(\)<a name="ga2c14344eed608ec8cd345a6c1c835a53"></a>

```
virtual [Rect](OHOS-Rect.md) OHOS::Window::GetRect ()
```

 **Description:**

Obtains the rectangle information \(position, width, and height\) of this window. 

**Returns:**

Returns the rectangle information of this window. 

## GetRootView\(\)<a name="ga0f81825ac2f7acd742d114627d007dc0"></a>

```
virtual [RootView](OHOS-RootView.md)* OHOS::Window::GetRootView ()
```

 **Description:**

Obtains the  **[RootView](OHOS-RootView.md)**  bound to this window. 

**Returns:**

Returns the  **[RootView](OHOS-RootView.md)**  if available; returns  **nullptr**  otherwise. 

## GetWindowId\(\)<a name="ga7efafa2bc07e9a0b5fc5c4c8b1b17b89"></a>

```
virtual int32_t OHOS::Window::GetWindowId ()
```

 **Description:**

Obtains the unique ID of this window. 

The window ID is within \[0, 31\]. An ID will be reused after the current window is destroyed. A maximum of 32 windows can be displayed at the same time.

**Returns:**

Returns the unique ID of this window if the operation is successful; returns  **-1**  otherwise. 

## Hide\(\)<a name="ga37272c50d164a77bf004c18174d94736"></a>

```
virtual void OHOS::Window::Hide ()
```

 **Description:**

Hides this window. 

## LowerToBottom\(\)<a name="ga61c01a10b37843abf8cf348bd7d1d659"></a>

```
virtual void OHOS::Window::LowerToBottom ()
```

 **Description:**

Lowers this window to the bottom. 

## MoveTo\(\)<a name="ga7454cb1c3c28e68f4e962fef108a0d2f"></a>

```
virtual void OHOS::Window::MoveTo (int16_t x, int16_t y )
```

 **Description:**

Moves this window to a specified position. 

**Parameters:**

<a name="table1895344758165625"></a>
<table><thead align="left"><tr id="row1265319197165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p892251560165625"><a name="p892251560165625"></a><a name="p892251560165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p219197436165625"><a name="p219197436165625"></a><a name="p219197436165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1441172888165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the x-coordinate of the target position. </td>
</tr>
<tr id="row813280213165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the y-coordinate of the target position. </td>
</tr>
</tbody>
</table>

## RaiseToTop\(\)<a name="ga395aa07d4a622059c627d18ecd2ff115"></a>

```
virtual void OHOS::Window::RaiseToTop ()
```

 **Description:**

Raises this window to the top. 

## Resize\(\)<a name="gac2c1bf9dc681741eb9c0490785bd73c2"></a>

```
virtual void OHOS::Window::Resize (int16_t width, int16_t height )
```

 **Description:**

Resizes this window. 

**Parameters:**

<a name="table1418225697165625"></a>
<table><thead align="left"><tr id="row849094904165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1374491041165625"><a name="p1374491041165625"></a><a name="p1374491041165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p897379683165625"><a name="p897379683165625"></a><a name="p897379683165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row515997998165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">width</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the new window width. </td>
</tr>
<tr id="row136945182165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">height</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the new window height. </td>
</tr>
</tbody>
</table>

## Show\(\)<a name="ga920aaa7deb0054c1436b2aaba3a81e4f"></a>

```
virtual void OHOS::Window::Show ()
```

 **Description:**

Shows this window. 

## UnbindRootView\(\)<a name="ga7ad1bbc5a9a758e48a0fcecc10512bf2"></a>

```
virtual void OHOS::Window::UnbindRootView ()
```

 **Description:**

Unbinds the  **[RootView](OHOS-RootView.md)**  from this window. 

## **Variable **<a name="section1566951119165625"></a>

## opacity<a name="ga848d59949e340c4c2572c49212eb6f5a"></a>

```
uint8_t OHOS::WindowConfig::opacity
```

 **Description:**

Opacity, within \[0, 255\] 

## option<a name="gae5bf33ab2eecd5dcafe2eb3da43d6f27"></a>

```
uint32_t OHOS::WindowConfig::option
```

 **Description:**

Other options 

## pixelFormat<a name="ga213fd5a52a7232dd4fbaef7108e2a36a"></a>

```
[WindowPixelFormat](Window.md#gade9f6a70c1e8547785d266aab3ca5725) OHOS::WindowConfig::pixelFormat
```

 **Description:**

Pixel format 

## rect<a name="gabb7c9c7f86fb9f1d29728ca0afa10668"></a>

```
[Rect](OHOS-Rect.md) OHOS::WindowConfig::rect
```

 **Description:**

[Rectangle](Rectangle.md) 

