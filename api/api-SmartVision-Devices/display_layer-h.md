# display\_layer.h<a name="ZH-CN_TOPIC_0000001054718091"></a>

-   [Overview](#section540260084165626)
-   [Summary](#section667560582165626)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section540260084165626"></a>

**Related Modules:**

[Display](Display.md)

**Description:**

Declares the driver functions for implementing layer operations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section667560582165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1832901949165626"></a>
<table><thead align="left"><tr id="row1574997663165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p975036037165626"><a name="p975036037165626"></a><a name="p975036037165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p882704732165626"><a name="p882704732165626"></a><a name="p882704732165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1458762393165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1782317801165626"><a name="p1782317801165626"></a><a name="p1782317801165626"></a><a href="LayerFuncs.md">LayerFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368560663165626"><a name="p1368560663165626"></a><a name="p1368560663165626"></a>Defines pointers to the layer driver functions. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table227189970165626"></a>
<table><thead align="left"><tr id="row1841989349165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2014775184165626"><a name="p2014775184165626"></a><a name="p2014775184165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1085531504165626"><a name="p1085531504165626"></a><a name="p1085531504165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row464866901165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p107196944165626"><a name="p107196944165626"></a><a name="p107196944165626"></a><a href="Display.md#ga061e587306a5d0367ff228d64434c05d">LayerInitialize</a> (<a href="LayerFuncs.md">LayerFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p811928713165626"><a name="p811928713165626"></a><a name="p811928713165626"></a>int32_t </p>
<p id="p130327303165626"><a name="p130327303165626"></a><a name="p130327303165626"></a>Initializes the layer to apply for resources used by the layer and obtain the pointer to functions for layer operations. </p>
</td>
</tr>
<tr id="row775022447165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1205387736165626"><a name="p1205387736165626"></a><a name="p1205387736165626"></a><a href="Display.md#ga4e32b1a65cf243a9ac015b632a4eea0b">LayerUninitialize</a> (<a href="LayerFuncs.md">LayerFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p119767009165626"><a name="p119767009165626"></a><a name="p119767009165626"></a>int32_t </p>
<p id="p648027788165626"><a name="p648027788165626"></a><a name="p648027788165626"></a>Deinitializes the layer module to release the memory allocated to the pointer to functions for layer operations. </p>
</td>
</tr>
</tbody>
</table>

