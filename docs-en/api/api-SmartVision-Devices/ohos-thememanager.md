# OHOS::ThemeManager<a name="EN-US_TOPIC_0000001055358142"></a>

-   [Overview](#section2010334454165635)
-   [Summary](#section236495670165635)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section2010334454165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Declares the singleton class used to manage the current screen theme of an application. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section236495670165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table784910925165635"></a>
<table><thead align="left"><tr id="row1520741026165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1322657380165635"><a name="p1322657380165635"></a><a name="p1322657380165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p504124416165635"><a name="p504124416165635"></a><a name="p504124416165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1818901241165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1155355192165635"><a name="p1155355192165635"></a><a name="p1155355192165635"></a><a href="graphic.md#ga6c4963d3186afc52db0d0a18bd52820f">SetCurrent</a> (<a href="ohos-theme.md">Theme</a> *theme)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p909627554165635"><a name="p909627554165635"></a><a name="p909627554165635"></a>void </p>
<p id="p1991332448165635"><a name="p1991332448165635"></a><a name="p1991332448165635"></a>Sets the current screen theme for this application. </p>
</td>
</tr>
<tr id="row1313597669165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1098384300165635"><a name="p1098384300165635"></a><a name="p1098384300165635"></a><a href="graphic.md#ga6aeed87ecd925de4262763f20cd940d5">GetCurrent</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p392342217165635"><a name="p392342217165635"></a><a name="p392342217165635"></a><a href="ohos-theme.md">Theme</a> * </p>
<p id="p1232616196165635"><a name="p1232616196165635"></a><a name="p1232616196165635"></a>Obtains the current screen theme of this application. </p>
</td>
</tr>
<tr id="row1778796965165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1585335586165635"><a name="p1585335586165635"></a><a name="p1585335586165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978392171165635"><a name="p978392171165635"></a><a name="p978392171165635"></a>void * </p>
<p id="p1491524105165635"><a name="p1491524105165635"></a><a name="p1491524105165635"></a>Overrides the <strong id="b1694413449165635"><a name="b1694413449165635"></a><a name="b1694413449165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1628500910165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1098354154165635"><a name="p1098354154165635"></a><a name="p1098354154165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p426533174165635"><a name="p426533174165635"></a><a name="p426533174165635"></a>void </p>
<p id="p1252416987165635"><a name="p1252416987165635"></a><a name="p1252416987165635"></a>Overrides the <strong id="b2093847532165635"><a name="b2093847532165635"></a><a name="b2093847532165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table1998558959165635"></a>
<table><thead align="left"><tr id="row1949875897165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p331391281165635"><a name="p331391281165635"></a><a name="p331391281165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1293866092165635"><a name="p1293866092165635"></a><a name="p1293866092165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row258461410165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1713175048165635"><a name="p1713175048165635"></a><a name="p1713175048165635"></a><a href="graphic.md#gaf98c321c61e63bdfdc1a0eed3735084b">GetInstance</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p717966580165635"><a name="p717966580165635"></a><a name="p717966580165635"></a>static <a href="ohos-thememanager.md">ThemeManager</a> &amp; </p>
<p id="p265131579165635"><a name="p265131579165635"></a><a name="p265131579165635"></a>Obtains the singleton instance of the <strong id="b1533802215165635"><a name="b1533802215165635"></a><a name="b1533802215165635"></a><a href="ohos-thememanager.md">ThemeManager</a></strong> class. </p>
</td>
</tr>
</tbody>
</table>

