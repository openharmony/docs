# iunknown.h<a name="EN-US_TOPIC_0000001055039488"></a>

-   [Overview](#section602857521165627)
-   [Summary](#section2069362633165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section602857521165627"></a>

**Related Modules:**

[Samgr](samgr.md)

**Description:**

Provides the base class and default implementation for external functions of system capabilities. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2069362633165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table2136293975165627"></a>
<table><thead align="left"><tr id="row281875032165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p806978118165627"><a name="p806978118165627"></a><a name="p806978118165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1537313015165627"><a name="p1537313015165627"></a><a name="p1537313015165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1666977372165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578737560165627"><a name="p578737560165627"></a><a name="p578737560165627"></a><a href="iunknown.md">IUnknown</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p323324088165627"><a name="p323324088165627"></a><a name="p323324088165627"></a>Defines the <strong id="b2124318901165627"><a name="b2124318901165627"></a><a name="b2124318901165627"></a><a href="iunknown.md">IUnknown</a></strong> class. </p>
</td>
</tr>
<tr id="row695670045165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1827250262165627"><a name="p1827250262165627"></a><a name="p1827250262165627"></a><a href="iunknownentry.md">IUnknownEntry</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391997141165627"><a name="p391997141165627"></a><a name="p391997141165627"></a>Defines the <strong id="b2006769989165627"><a name="b2006769989165627"></a><a name="b2006769989165627"></a><a href="iunknown.md">IUnknown</a></strong> implementation class. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1492722763165627"></a>
<table><thead align="left"><tr id="row1126837621165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1721872396165627"><a name="p1721872396165627"></a><a name="p1721872396165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p32501598165627"><a name="p32501598165627"></a><a name="p32501598165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1711815717165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1525780448165627"><a name="p1525780448165627"></a><a name="p1525780448165627"></a><a href="samgr.md#ga13dae059206df8d2d9b9b42e694b3f9c">DEFAULT_VERSION</a>   0x20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078419349165627"><a name="p1078419349165627"></a><a name="p1078419349165627"></a>Defines the default <a href="iunknown.md">IUnknown</a> version. You can customize the version. </p>
</td>
</tr>
<tr id="row1150494099165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p695647018165627"><a name="p695647018165627"></a><a name="p695647018165627"></a><a href="samgr.md#gab74532a22d6993d0ffc014d36253397f">INHERIT_IUNKNOWN</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p112605901165627"><a name="p112605901165627"></a><a name="p112605901165627"></a>Defines the macro for inheriting the <strong id="b1260235022165627"><a name="b1260235022165627"></a><a name="b1260235022165627"></a><a href="iunknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row102487702165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137160402165627"><a name="p137160402165627"></a><a name="p137160402165627"></a><a href="samgr.md#gad6324fd90dd636180efa2a59b377e65c">INHERIT_IUNKNOWNENTRY</a>(T)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442992638165627"><a name="p442992638165627"></a><a name="p442992638165627"></a>Defines the macro for inheriting the classes that implement the <strong id="b860186146165627"><a name="b860186146165627"></a><a name="b860186146165627"></a><a href="iunknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row1306436991165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p452695988165627"><a name="p452695988165627"></a><a name="p452695988165627"></a><a href="samgr.md#gac8d8c9671531f9340427153d50ca4a2b">DEFAULT_IUNKNOWN_IMPL</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p842147112165627"><a name="p842147112165627"></a><a name="p842147112165627"></a>Defines the default marco for initializing the <strong id="b1739664968165627"><a name="b1739664968165627"></a><a name="b1739664968165627"></a><a href="iunknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row1772017385165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162869237165627"><a name="p162869237165627"></a><a name="p162869237165627"></a><a href="samgr.md#ga52ec6b5b03d56b0dfe7277785246bda1">IUNKNOWN_ENTRY_BEGIN</a>(version)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677069384165627"><a name="p1677069384165627"></a><a name="p1677069384165627"></a>Defines the macro for initializing the classes that implement the <strong id="b1383552506165627"><a name="b1383552506165627"></a><a name="b1383552506165627"></a><a href="iunknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row1361634284165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1014213856165627"><a name="p1014213856165627"></a><a name="p1014213856165627"></a><a href="samgr.md#ga4ef734474ece49aa938d8ebd5b54bdb3">IUNKNOWN_ENTRY_END</a>   }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1962181326165627"><a name="p1962181326165627"></a><a name="p1962181326165627"></a><a href="iunknown.md">IUnknown</a> Defines the end macro for initializing the <strong id="b634423474165627"><a name="b634423474165627"></a><a name="b634423474165627"></a><a href="iunknown.md">IUnknown</a></strong> implementation object. </p>
</td>
</tr>
<tr id="row472681087165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072189767165627"><a name="p1072189767165627"></a><a name="p1072189767165627"></a><a href="samgr.md#ga9403f55c3f75fd03854dcd37c231e05b">GET_IUNKNOWN</a>(T)   (<a href="iunknown.md">IUnknown</a> *)(&amp;((T).iUnknown))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480681773165627"><a name="p1480681773165627"></a><a name="p1480681773165627"></a>Obtains the pointer of the <strong id="b1882315682165627"><a name="b1882315682165627"></a><a name="b1882315682165627"></a><a href="iunknown.md">IUnknown</a></strong> interface object from the subclass object T (generic macro) of the <strong id="b799852004165627"><a name="b799852004165627"></a><a name="b799852004165627"></a><a href="iunknown.md">IUnknown</a></strong> implementation class. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table689493581165627"></a>
<table><thead align="left"><tr id="row761709895165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p560893532165627"><a name="p560893532165627"></a><a name="p560893532165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p38941517165627"><a name="p38941517165627"></a><a name="p38941517165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1911701413165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1874216196165627"><a name="p1874216196165627"></a><a name="p1874216196165627"></a><a href="samgr.md#gacaa7db32a018a33a2bbf919cde8d8f9c">IUnknownEntry</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p686858065165627"><a name="p686858065165627"></a><a name="p686858065165627"></a>typedef struct <a href="iunknownentry.md">IUnknownEntry</a> </p>
<p id="p1331908043165627"><a name="p1331908043165627"></a><a name="p1331908043165627"></a>Defines the <strong id="b1754739707165627"><a name="b1754739707165627"></a><a name="b1754739707165627"></a><a href="iunknown.md">IUnknown</a></strong> implementation class. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table944492669165627"></a>
<table><thead align="left"><tr id="row982979863165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p647393227165627"><a name="p647393227165627"></a><a name="p647393227165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1748802142165627"><a name="p1748802142165627"></a><a name="p1748802142165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row331379279165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1758561074165627"><a name="p1758561074165627"></a><a name="p1758561074165627"></a><a href="samgr.md#ga9abef49ec89bf913c3bed03faf478c1e">IUNKNOWN_AddRef</a> (<a href="iunknown.md">IUnknown</a> *iUnknown)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441976655165627"><a name="p441976655165627"></a><a name="p441976655165627"></a>int </p>
<p id="p2139592313165627"><a name="p2139592313165627"></a><a name="p2139592313165627"></a>Increments the reference count in this <strong id="b220853590165627"><a name="b220853590165627"></a><a name="b220853590165627"></a><a href="iunknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row576216127165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1518202970165627"><a name="p1518202970165627"></a><a name="p1518202970165627"></a><a href="samgr.md#gac857d12648500c7dab1cb43e85ae2ed4">IUNKNOWN_QueryInterface</a> (<a href="iunknown.md">IUnknown</a> *iUnknown, int ver, void **target)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p718960503165627"><a name="p718960503165627"></a><a name="p718960503165627"></a>int </p>
<p id="p641336029165627"><a name="p641336029165627"></a><a name="p641336029165627"></a>Queries the <strong id="b1190167657165627"><a name="b1190167657165627"></a><a name="b1190167657165627"></a><a href="iunknown.md">IUnknown</a></strong> interfaces of a specified version (downcasting). </p>
</td>
</tr>
<tr id="row1224370725165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1756609354165627"><a name="p1756609354165627"></a><a name="p1756609354165627"></a><a href="samgr.md#gabd462f8a5e6460a68760cd0719982296">IUNKNOWN_Release</a> (<a href="iunknown.md">IUnknown</a> *iUnknown)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2037943935165627"><a name="p2037943935165627"></a><a name="p2037943935165627"></a>int </p>
<p id="p2051212538165627"><a name="p2051212538165627"></a><a name="p2051212538165627"></a>Releases a reference to an <strong id="b198106022165627"><a name="b198106022165627"></a><a name="b198106022165627"></a><a href="iunknown.md">IUnknown</a></strong> interface that is no longer used. </p>
</td>
</tr>
</tbody>
</table>

