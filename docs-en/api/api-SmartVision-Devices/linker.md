# LINKER<a name="EN-US_TOPIC_0000001054948029"></a>

-   [Overview](#section130839916165622)
-   [Summary](#section1847008323165622)
-   [Files](#files)
-   [Macros](#define-members)
-   [Functions](#func-members)
-   [Details](#section2035573446165622)
-   [Function](#section1817236284165622)
-   [dlclose\(\)](#gaf483b6c4400965aa885f9f1a144138a5)
-   [dlerror\(\)](#ga541c343ae5cdf90926014c65972c86cc)
-   [dlopen\(\)](#gad559be443b3edb0af8835d6ec2c29a3a)
-   [dlsym\(\)](#ga84cb8784df910bfcc3002dc5e9e2f406)

## **Overview**<a name="section130839916165622"></a>

**Description:**

Provides functions and structures related to linking and loading. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1847008323165622"></a>

## Files<a name="files"></a>

<a name="table1617055159165622"></a>
<table><thead align="left"><tr id="row1376270043165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p449496893165622"><a name="p449496893165622"></a><a name="p449496893165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p214483200165622"><a name="p214483200165622"></a><a name="p214483200165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row970576256165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p188255967165622"><a name="p188255967165622"></a><a name="p188255967165622"></a><a href="dlfcn-h.md">dlfcn.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p303166455165622"><a name="p303166455165622"></a><a name="p303166455165622"></a>Provides functions and structures related to linking and loading. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1312161315165622"></a>
<table><thead align="left"><tr id="row1113822368165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1531529492165622"><a name="p1531529492165622"></a><a name="p1531529492165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p863594023165622"><a name="p863594023165622"></a><a name="p863594023165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1050415929165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p678303427165622"><a name="p678303427165622"></a><a name="p678303427165622"></a><em id="ga5c83709ee3bd7d316f8f47e122f3be20"><a name="ga5c83709ee3bd7d316f8f47e122f3be20"></a><a name="ga5c83709ee3bd7d316f8f47e122f3be20"></a></em>RTLD_LAZY    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p60408961165622"><a name="p60408961165622"></a><a name="p60408961165622"></a>All undefined symbols in the shared object are not resolved before <a href="linker.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen()</a> returns. </p>
</td>
</tr>
<tr id="row300886021165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p464500045165622"><a name="p464500045165622"></a><a name="p464500045165622"></a><em id="ga98a6517467cf7d1dd27d6c6dce78a6cf"><a name="ga98a6517467cf7d1dd27d6c6dce78a6cf"></a><a name="ga98a6517467cf7d1dd27d6c6dce78a6cf"></a></em>RTLD_NOW    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1189634708165622"><a name="p1189634708165622"></a><a name="p1189634708165622"></a>All undefined symbols in the shared object are resolved before <a href="linker.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen()</a> returns. </p>
</td>
</tr>
<tr id="row31744223165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1263736861165622"><a name="p1263736861165622"></a><a name="p1263736861165622"></a><em id="ga65cc8226321c99d43c9d854b0fb86081"><a name="ga65cc8226321c99d43c9d854b0fb86081"></a><a name="ga65cc8226321c99d43c9d854b0fb86081"></a></em>RTLD_NOLOAD    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964461881165622"><a name="p1964461881165622"></a><a name="p1964461881165622"></a>The shared object is not loaded. It can be used to test whether the object resides in the memory. </p>
</td>
</tr>
<tr id="row1413269365165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76935932165622"><a name="p76935932165622"></a><a name="p76935932165622"></a><em id="ga63b65253a063469ae964534ab38fe635"><a name="ga63b65253a063469ae964534ab38fe635"></a><a name="ga63b65253a063469ae964534ab38fe635"></a></em>RTLD_NODELETE    4096</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339995740165622"><a name="p339995740165622"></a><a name="p339995740165622"></a>The shared object is not deleted during <a href="linker.md#gaf483b6c4400965aa885f9f1a144138a5">dlclose()</a>. </p>
</td>
</tr>
<tr id="row1988129487165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1608957895165622"><a name="p1608957895165622"></a><a name="p1608957895165622"></a><em id="gace65454279c135fe5e6168d456c31263"><a name="gace65454279c135fe5e6168d456c31263"></a><a name="gace65454279c135fe5e6168d456c31263"></a></em>RTLD_GLOBAL    256</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206837565165622"><a name="p206837565165622"></a><a name="p206837565165622"></a>The symbols defined by the loaded shared object can be resolved by other shared objects opened later. </p>
</td>
</tr>
<tr id="row1632833339165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532928726165622"><a name="p532928726165622"></a><a name="p532928726165622"></a><em id="ga233010260f7e61c5dab09e2bca10a590"><a name="ga233010260f7e61c5dab09e2bca10a590"></a><a name="ga233010260f7e61c5dab09e2bca10a590"></a></em>RTLD_LOCAL    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p111786902165622"><a name="p111786902165622"></a><a name="p111786902165622"></a>The symbols defined by the loaded shared object cannot be resolved by other shared objects opened later. </p>
</td>
</tr>
<tr id="row1621648236165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122252220165622"><a name="p1122252220165622"></a><a name="p1122252220165622"></a><em id="ga51d4212b17b1edeb2fc5a48c7c497267"><a name="ga51d4212b17b1edeb2fc5a48c7c497267"></a><a name="ga51d4212b17b1edeb2fc5a48c7c497267"></a></em>RTLD_NEXT    ((void *)-1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2115653671165622"><a name="p2115653671165622"></a><a name="p2115653671165622"></a>The next match of the required symbol is searched in the search order after the current object. </p>
</td>
</tr>
<tr id="row1489637146165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873391576165622"><a name="p1873391576165622"></a><a name="p1873391576165622"></a><em id="ga58d13c5dcabbb85848fa97b446086247"><a name="ga58d13c5dcabbb85848fa97b446086247"></a><a name="ga58d13c5dcabbb85848fa97b446086247"></a></em>RTLD_DEFAULT    ((void *)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p828889050165622"><a name="p828889050165622"></a><a name="p828889050165622"></a>The first match of the required symbol is searched in the default shared object search order. The search scope includes the global symbols of the program and its dependencies, and the global symbols loaded by the <a href="linker.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen()</a> function. </p>
</td>
</tr>
<tr id="row831462163165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1714690600165622"><a name="p1714690600165622"></a><a name="p1714690600165622"></a><em id="gafc522c1a0d6100a1af90b59ded39ef91"><a name="gafc522c1a0d6100a1af90b59ded39ef91"></a><a name="gafc522c1a0d6100a1af90b59ded39ef91"></a></em>RTLD_DI_LINKMAP    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p278266868165622"><a name="p278266868165622"></a><a name="p278266868165622"></a>The pointer to the <strong id="b803683997165622"><a name="b803683997165622"></a><a name="b803683997165622"></a>link_map</strong> structure of the specified handle. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table54518710165622"></a>
<table><thead align="left"><tr id="row1513958751165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1322704976165622"><a name="p1322704976165622"></a><a name="p1322704976165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1559891044165622"><a name="p1559891044165622"></a><a name="p1559891044165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row852024748165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p638376774165622"><a name="p638376774165622"></a><a name="p638376774165622"></a><a href="linker.md#gaf483b6c4400965aa885f9f1a144138a5">dlclose</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036930374165622"><a name="p1036930374165622"></a><a name="p1036930374165622"></a>int </p>
<p id="p32092676165622"><a name="p32092676165622"></a><a name="p32092676165622"></a>Closes the DLL of a specified handle. </p>
</td>
</tr>
<tr id="row1146680835165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798686254165622"><a name="p798686254165622"></a><a name="p798686254165622"></a><a href="linker.md#ga541c343ae5cdf90926014c65972c86cc">dlerror</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734198530165622"><a name="p734198530165622"></a><a name="p734198530165622"></a>char * </p>
<p id="p1682472587165622"><a name="p1682472587165622"></a><a name="p1682472587165622"></a>Obtains the latest error that occurred during a DLL function execution failure. </p>
</td>
</tr>
<tr id="row1563135587165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983328685165622"><a name="p1983328685165622"></a><a name="p1983328685165622"></a><a href="linker.md#gad559be443b3edb0af8835d6ec2c29a3a">dlopen</a> (const char *filename, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p378429092165622"><a name="p378429092165622"></a><a name="p378429092165622"></a>void * </p>
<p id="p733932405165622"><a name="p733932405165622"></a><a name="p733932405165622"></a>Opens a DLL and returns its handle. </p>
</td>
</tr>
<tr id="row1297193012165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p883673436165622"><a name="p883673436165622"></a><a name="p883673436165622"></a><a href="linker.md#ga84cb8784df910bfcc3002dc5e9e2f406">dlsym</a> (void *handle, const char *symbol)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p654570847165622"><a name="p654570847165622"></a><a name="p654570847165622"></a>void * </p>
<p id="p165772563165622"><a name="p165772563165622"></a><a name="p165772563165622"></a>Searches for a specified symbol based on the DLL handle. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2035573446165622"></a>

## **Function **<a name="section1817236284165622"></a>

## dlclose\(\)<a name="gaf483b6c4400965aa885f9f1a144138a5"></a>

```
int dlclose (void * handle)
```

 **Description:**

Closes the DLL of a specified handle. 

**Parameters:**

<a name="table1617846647165622"></a>
<table><thead align="left"><tr id="row384041178165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p883236801165622"><a name="p883236801165622"></a><a name="p883236801165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1333679701165622"><a name="p1333679701165622"></a><a name="p1333679701165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1152287795165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the loaded DLL handle. </td>
</tr>
</tbody>
</table>

**Attention:**

The symbols associated with the handle may not be removed from the caller's address space even if the  **[dlclose\(\)](linker.md#gaf483b6c4400965aa885f9f1a144138a5)**  function returns. The symbols are removed only when the reference count of the DLL is 0. The reference count is incremented \(by 1\) each time the  **[dlopen\(\)](linker.md#gad559be443b3edb0af8835d6ec2c29a3a)**  function is explicitly called. In addition, the reference of DLL depended on by other DLLs or programs will be counted if it has been implicitly loaded. A shared object can be removed from the address space only after all references are released.

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value if the operation fails. 

## dlerror\(\)<a name="ga541c343ae5cdf90926014c65972c86cc"></a>

```
char* dlerror (void )
```

 **Description:**

Obtains the latest error that occurred during a DLL function execution failure. 

**Returns:**

Returns the error if occurred; returns  **NULL**  if the DLL function execution is successful. 

## dlopen\(\)<a name="gad559be443b3edb0af8835d6ec2c29a3a"></a>

```
void* dlopen (const char * filename, int flags )
```

 **Description:**

Opens a DLL and returns its handle. 

**Parameters:**

<a name="table1157168507165622"></a>
<table><thead align="left"><tr id="row1008211801165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1593615649165622"><a name="p1593615649165622"></a><a name="p1593615649165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1471469796165622"><a name="p1471469796165622"></a><a name="p1471469796165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1677221859165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">filename</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file name of the DLL. </td>
</tr>
<tr id="row121091321165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the flag of the DLL to be loaded. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the DLL handle if the operation is successful; returns  **NULL**  if the operation fails. 

## dlsym\(\)<a name="ga84cb8784df910bfcc3002dc5e9e2f406"></a>

```
void* dlsym (void * handle, const char * symbol )
```

 **Description:**

Searches for a specified symbol based on the DLL handle. 

You can also use this function to obtain the loading addresses of global variables. 

**Parameters:**

<a name="table1184055768165622"></a>
<table><thead align="left"><tr id="row571150439165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1724097354165622"><a name="p1724097354165622"></a><a name="p1724097354165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p684566176165622"><a name="p684566176165622"></a><a name="p684566176165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1010013810165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the loaded DLL handle. </td>
</tr>
<tr id="row1082420747165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">symbol</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the symbol name. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the symbol address if the operation is successful; returns  **NULL**  if the operation fails. 

