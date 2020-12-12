# display\_gralloc.h<a name="EN-US_TOPIC_0000001054918119"></a>

-   [Overview](#section1206286449165626)
-   [Summary](#section1378872115165626)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1206286449165626"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Declares the driver functions for memory. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1378872115165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1242661663165626"></a>
<table><thead align="left"><tr id="row1698984901165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1513740223165626"><a name="p1513740223165626"></a><a name="p1513740223165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p25788689165626"><a name="p25788689165626"></a><a name="p25788689165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row933417205165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p645805902165626"><a name="p645805902165626"></a><a name="p645805902165626"></a><a href="grallocfuncs.md">GrallocFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1433805869165626"><a name="p1433805869165626"></a><a name="p1433805869165626"></a>Defines pointers to the memory driver functions. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1613689901165626"></a>
<table><thead align="left"><tr id="row31474069165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2030846964165626"><a name="p2030846964165626"></a><a name="p2030846964165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1550390014165626"><a name="p1550390014165626"></a><a name="p1550390014165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1023318396165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626760272165626"><a name="p1626760272165626"></a><a name="p1626760272165626"></a><a href="display.md#ga304347c32a67bf7b20ef5d2b5714e5fa">GrallocInitialize</a> (<a href="grallocfuncs.md">GrallocFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p121571450165626"><a name="p121571450165626"></a><a name="p121571450165626"></a>int32_t </p>
<p id="p1098923781165626"><a name="p1098923781165626"></a><a name="p1098923781165626"></a>Initializes the memory module to obtain the pointer to functions for memory operations. </p>
</td>
</tr>
<tr id="row447636821165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376659317165626"><a name="p376659317165626"></a><a name="p376659317165626"></a><a href="display.md#ga8842b25f91c247606048ab2d5cdb338f">GrallocUninitialize</a> (<a href="grallocfuncs.md">GrallocFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532271239165626"><a name="p1532271239165626"></a><a name="p1532271239165626"></a>int32_t </p>
<p id="p1282905400165626"><a name="p1282905400165626"></a><a name="p1282905400165626"></a>Deinitializes the memory module to release the memory allocated to the pointer to functions for memory operations. </p>
</td>
</tr>
</tbody>
</table>

