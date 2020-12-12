# dlfcn.h<a name="ZH-CN_TOPIC_0000001054748005"></a>

-   [Overview](#section399055370165626)
-   [Summary](#section28632875165626)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section399055370165626"></a>

**Related Modules:**

[LINKER](LINKER.md)

**Description:**

Provides functions and structures related to linking and loading. 

This file provides functions and structures for opening and closing a dynamic-link library \(DLL\) and searching for the specified symbols based on the DLL. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section28632875165626"></a>

## Macros<a name="define-members"></a>

<a name="table2014076403165626"></a>
<table><thead align="left"><tr id="row1741928055165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1256094048165626"><a name="p1256094048165626"></a><a name="p1256094048165626"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1299147427165626"><a name="p1299147427165626"></a><a name="p1299147427165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1565273481165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p119009081165626"><a name="p119009081165626"></a><a name="p119009081165626"></a><a href="LINKER.md#ga5c83709ee3bd7d316f8f47e122f3be20">RTLD_LAZY</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356426335165626"><a name="p356426335165626"></a><a name="p356426335165626"></a>All undefined symbols in the shared object are not resolved before <a href="LINKER.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen()</a> returns. </p>
</td>
</tr>
<tr id="row14376398165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1666821191165626"><a name="p1666821191165626"></a><a name="p1666821191165626"></a><a href="LINKER.md#ga98a6517467cf7d1dd27d6c6dce78a6cf">RTLD_NOW</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1939829345165626"><a name="p1939829345165626"></a><a name="p1939829345165626"></a>All undefined symbols in the shared object are resolved before <a href="LINKER.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen()</a> returns. </p>
</td>
</tr>
<tr id="row1178917312165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1953889060165626"><a name="p1953889060165626"></a><a name="p1953889060165626"></a><a href="LINKER.md#ga65cc8226321c99d43c9d854b0fb86081">RTLD_NOLOAD</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32367616165626"><a name="p32367616165626"></a><a name="p32367616165626"></a>The shared object is not loaded. It can be used to test whether the object resides in the memory. </p>
</td>
</tr>
<tr id="row838283984165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682286740165626"><a name="p1682286740165626"></a><a name="p1682286740165626"></a><a href="LINKER.md#ga63b65253a063469ae964534ab38fe635">RTLD_NODELETE</a>   4096</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1795199727165626"><a name="p1795199727165626"></a><a name="p1795199727165626"></a>The shared object is not deleted during <a href="LINKER.md#gaf483b6c4400965aa885f9f1a144138a5">dlclose()</a>. </p>
</td>
</tr>
<tr id="row455637116165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448534283165626"><a name="p448534283165626"></a><a name="p448534283165626"></a><a href="LINKER.md#gace65454279c135fe5e6168d456c31263">RTLD_GLOBAL</a>   256</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p728344664165626"><a name="p728344664165626"></a><a name="p728344664165626"></a>The symbols defined by the loaded shared object can be resolved by other shared objects opened later. </p>
</td>
</tr>
<tr id="row847426621165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381727457165626"><a name="p1381727457165626"></a><a name="p1381727457165626"></a><a href="LINKER.md#ga233010260f7e61c5dab09e2bca10a590">RTLD_LOCAL</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p878892808165626"><a name="p878892808165626"></a><a name="p878892808165626"></a>The symbols defined by the loaded shared object cannot be resolved by other shared objects opened later. </p>
</td>
</tr>
<tr id="row2117044909165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009551481165626"><a name="p1009551481165626"></a><a name="p1009551481165626"></a><a href="LINKER.md#ga51d4212b17b1edeb2fc5a48c7c497267">RTLD_NEXT</a>   ((void *)-1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p674940335165626"><a name="p674940335165626"></a><a name="p674940335165626"></a>The next match of the required symbol is searched in the search order after the current object. </p>
</td>
</tr>
<tr id="row2115954099165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p179042237165626"><a name="p179042237165626"></a><a name="p179042237165626"></a><a href="LINKER.md#ga58d13c5dcabbb85848fa97b446086247">RTLD_DEFAULT</a>   ((void *)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p521790621165626"><a name="p521790621165626"></a><a name="p521790621165626"></a>The first match of the required symbol is searched in the default shared object search order. The search scope includes the global symbols of the program and its dependencies, and the global symbols loaded by the <a href="LINKER.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen()</a> function. </p>
</td>
</tr>
<tr id="row1200223343165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1798847018165626"><a name="p1798847018165626"></a><a name="p1798847018165626"></a><a href="LINKER.md#gafc522c1a0d6100a1af90b59ded39ef91">RTLD_DI_LINKMAP</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1414946656165626"><a name="p1414946656165626"></a><a name="p1414946656165626"></a>The pointer to the <strong id="b169073013165626"><a name="b169073013165626"></a><a name="b169073013165626"></a>link_map</strong> structure of the specified handle. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table708955872165626"></a>
<table><thead align="left"><tr id="row1343063126165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1957380637165626"><a name="p1957380637165626"></a><a name="p1957380637165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p35739922165626"><a name="p35739922165626"></a><a name="p35739922165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row137022735165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p238477161165626"><a name="p238477161165626"></a><a name="p238477161165626"></a><a href="LINKER.md#gaf483b6c4400965aa885f9f1a144138a5">dlclose</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p717387381165626"><a name="p717387381165626"></a><a name="p717387381165626"></a>int </p>
<p id="p1668023881165626"><a name="p1668023881165626"></a><a name="p1668023881165626"></a>Closes the DLL of a specified handle. </p>
</td>
</tr>
<tr id="row756568812165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p398293225165626"><a name="p398293225165626"></a><a name="p398293225165626"></a><a href="LINKER.md#ga541c343ae5cdf90926014c65972c86cc">dlerror</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39486976165626"><a name="p39486976165626"></a><a name="p39486976165626"></a>char * </p>
<p id="p938010783165626"><a name="p938010783165626"></a><a name="p938010783165626"></a>Obtains the latest error that occurred during a DLL function execution failure. </p>
</td>
</tr>
<tr id="row1929165508165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034150551165626"><a name="p2034150551165626"></a><a name="p2034150551165626"></a><a href="LINKER.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen</a> (const char *filename, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1963594258165626"><a name="p1963594258165626"></a><a name="p1963594258165626"></a>void * </p>
<p id="p2062514650165626"><a name="p2062514650165626"></a><a name="p2062514650165626"></a>Opens a DLL and returns its handle. </p>
</td>
</tr>
<tr id="row1010766499165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1945520440165626"><a name="p1945520440165626"></a><a name="p1945520440165626"></a><a href="LINKER.md#ga84cb8784df910bfcc3002dc5e9e2f406">dlsym</a> (void *handle, const char *symbol)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2044336834165626"><a name="p2044336834165626"></a><a name="p2044336834165626"></a>void * </p>
<p id="p1849892031165626"><a name="p1849892031165626"></a><a name="p1849892031165626"></a>Searches for a specified symbol based on the DLL handle. </p>
</td>
</tr>
</tbody>
</table>

