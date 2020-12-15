# common.h<a name="ZH-CN_TOPIC_0000001055228012"></a>

-   [Overview](#section1043119264165626)
-   [Summary](#section647703513165626)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1043119264165626"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Provides common objects and functions for Samgr and external modules. 

This file provides simplified vector containers and downcast functions. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section647703513165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1095224105165626"></a>
<table><thead align="left"><tr id="row312958098165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p489294262165626"><a name="p489294262165626"></a><a name="p489294262165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p165170199165626"><a name="p165170199165626"></a><a name="p165170199165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row818212086165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722262483165626"><a name="p722262483165626"></a><a name="p722262483165626"></a><a href="SimpleVector.md">SimpleVector</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663277354165626"><a name="p663277354165626"></a><a name="p663277354165626"></a>Defines the simplified vector class, which is extended by four elements. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1943359235165626"></a>
<table><thead align="left"><tr id="row883417621165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2100645307165626"><a name="p2100645307165626"></a><a name="p2100645307165626"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p404739128165626"><a name="p404739128165626"></a><a name="p404739128165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row593427987165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168409683165626"><a name="p168409683165626"></a><a name="p168409683165626"></a><a href="Samgr.md#gab094855efe05ae51eaaf3e0ddf0346cc">GET_OFFSIZE</a>(T, member)   (long)((char *)&amp;(((T *)(0))-&gt;member))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1157792939165626"><a name="p1157792939165626"></a><a name="p1157792939165626"></a>Calculates the offset of the member in the T type. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1066642663165626"></a>
<table><thead align="left"><tr id="row1652085270165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p277115651165626"><a name="p277115651165626"></a><a name="p277115651165626"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p505949555165626"><a name="p505949555165626"></a><a name="p505949555165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1844482327165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p632425541165626"><a name="p632425541165626"></a><a name="p632425541165626"></a><a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667687718165626"><a name="p667687718165626"></a><a name="p667687718165626"></a>typedef struct <a href="SimpleVector.md">SimpleVector</a> </p>
<p id="p1522872494165626"><a name="p1522872494165626"></a><a name="p1522872494165626"></a>Defines the simplified vector class, which is extended by four elements. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1007587659165626"></a>
<table><thead align="left"><tr id="row335023712165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p665651359165626"><a name="p665651359165626"></a><a name="p665651359165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p345995018165626"><a name="p345995018165626"></a><a name="p345995018165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1288478287165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868876721165626"><a name="p868876721165626"></a><a name="p868876721165626"></a><a href="Samgr.md#gae790345f8a2863c143bfee4bab3fb6d7">VECTOR_Make</a> (VECTOR_Key key, VECTOR_Compare compare)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1863113829165626"><a name="p1863113829165626"></a><a name="p1863113829165626"></a><a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> </p>
<p id="p147495106165626"><a name="p147495106165626"></a><a name="p147495106165626"></a>Creates or initializes a vector object. </p>
</td>
</tr>
<tr id="row340324644165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p759856513165626"><a name="p759856513165626"></a><a name="p759856513165626"></a><a href="Samgr.md#gaebfe9ac38f2667d61bf39420aa8e7035">VECTOR_Clear</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2074222190165626"><a name="p2074222190165626"></a><a name="p2074222190165626"></a>void </p>
<p id="p1043923983165626"><a name="p1043923983165626"></a><a name="p1043923983165626"></a>Destruct a vector object. </p>
</td>
</tr>
<tr id="row1244926884165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1955634923165626"><a name="p1955634923165626"></a><a name="p1955634923165626"></a><a href="Samgr.md#ga234ba2452c973e9fa4a8be47eaea9d06">VECTOR_Add</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, void *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2015849051165626"><a name="p2015849051165626"></a><a name="p2015849051165626"></a>int16 </p>
<p id="p265832825165626"><a name="p265832825165626"></a><a name="p265832825165626"></a>Adds an element to the vector. </p>
</td>
</tr>
<tr id="row1816854807165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1409728030165626"><a name="p1409728030165626"></a><a name="p1409728030165626"></a><a href="Samgr.md#ga1432f30c136d14bc00414d883d8be3bd">VECTOR_Size</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1274058975165626"><a name="p1274058975165626"></a><a name="p1274058975165626"></a>int16 </p>
<p id="p256542234165626"><a name="p256542234165626"></a><a name="p256542234165626"></a>Obtains the number of elements in the vector, including elements that have been set to <strong id="b1489608698165626"><a name="b1489608698165626"></a><a name="b1489608698165626"></a>NULL</strong>. </p>
</td>
</tr>
<tr id="row142296751165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1827668878165626"><a name="p1827668878165626"></a><a name="p1827668878165626"></a><a href="Samgr.md#ga90523bfd48091a0135f74670076af4d5">VECTOR_Num</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2094238123165626"><a name="p2094238123165626"></a><a name="p2094238123165626"></a>int16 </p>
<p id="p548919717165626"><a name="p548919717165626"></a><a name="p548919717165626"></a>Obtains the number of valid elements in the vector, excluding elements that have been set to <strong id="b874391633165626"><a name="b874391633165626"></a><a name="b874391633165626"></a>NULL</strong>. </p>
</td>
</tr>
<tr id="row756981569165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p171487551165626"><a name="p171487551165626"></a><a name="p171487551165626"></a><a href="Samgr.md#ga75210ba0bd37a38a1902c4904e61246a">VECTOR_At</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, int16 <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515477465165626"><a name="p1515477465165626"></a><a name="p1515477465165626"></a>void * </p>
<p id="p184255035165626"><a name="p184255035165626"></a><a name="p184255035165626"></a>Obtains the element at a specified position. </p>
</td>
</tr>
<tr id="row563833398165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1061487380165626"><a name="p1061487380165626"></a><a name="p1061487380165626"></a><a href="Samgr.md#ga7f435d33ba61d145de9d5892b68a0eda">VECTOR_Swap</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, int16 <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, void *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590426515165626"><a name="p590426515165626"></a><a name="p590426515165626"></a>void * </p>
<p id="p1949988620165626"><a name="p1949988620165626"></a><a name="p1949988620165626"></a>Swaps the element at a specified position in a vector with another element. </p>
</td>
</tr>
<tr id="row256870783165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073867278165626"><a name="p1073867278165626"></a><a name="p1073867278165626"></a><a href="Samgr.md#gaabc5b0eda1ee6889411e6dacb233cb07">VECTOR_Find</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, const void *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683293303165626"><a name="p683293303165626"></a><a name="p683293303165626"></a>int16 </p>
<p id="p993361302165626"><a name="p993361302165626"></a><a name="p993361302165626"></a>Checks the position of an element. </p>
</td>
</tr>
<tr id="row1478414305165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757759986165626"><a name="p757759986165626"></a><a name="p757759986165626"></a><a href="Samgr.md#gac65bc6dc959a90d95dff93368abd97c7">VECTOR_FindByKey</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, const void *key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2135787155165626"><a name="p2135787155165626"></a><a name="p2135787155165626"></a>int16 </p>
<p id="p470164275165626"><a name="p470164275165626"></a><a name="p470164275165626"></a>Checks the position of the element with a specified key. </p>
</td>
</tr>
</tbody>
</table>

