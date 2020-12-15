# hdf\_workqueue.h<a name="EN-US_TOPIC_0000001054718095"></a>

-   [Overview](#section319337871165627)
-   [Summary](#section852527649165627)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section319337871165627"></a>

**Related Modules:**

[DriverUtils](driverutils.md)

**Description:**

Declares work queue structures and interfaces. 

This file provides interfaces such as initializing a work queue, a work item, and a delayed work item, adding a work or delayed work item to a work queue, and destroying a work queue, a work item, and a delayed work item. You need to define a work queue, a work item, and a delayed work item, and then call the initialization function to initialize them. The work item, delayed work item, and work queue must be destroyed when they are no longer used.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section852527649165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1053100136165627"></a>
<table><thead align="left"><tr id="row392760712165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1041625315165627"><a name="p1041625315165627"></a><a name="p1041625315165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1298909567165627"><a name="p1298909567165627"></a><a name="p1298909567165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1366707981165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1533186190165627"><a name="p1533186190165627"></a><a name="p1533186190165627"></a><a href="hdfwork.md">HdfWork</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1039148095165627"><a name="p1039148095165627"></a><a name="p1039148095165627"></a>Describes a work item and a delayed work item. This structure defines the work and delayed work items, and then calls the initialization function <a href="driverutils.md#gad171adc8eda320fd01049a2b87ea62fb">HdfWorkInit</a> or <a href="driverutils.md#ga55bf669dc6740c65e4d45a4f641db2f1">HdfDelayedWorkInit</a> to perform initialization. The <strong id="b355999635165627"><a name="b355999635165627"></a><a name="b355999635165627"></a><a href="driverutils.md#ga82cc68d656aa17317634b07d49dae160">HdfAddWork()</a></strong> function is to add a work item to a work queue immediately, and the <strong id="b670217097165627"><a name="b670217097165627"></a><a name="b670217097165627"></a><a href="driverutils.md#gaef781ccc1579db3070745088da47b2c5">HdfAddDelayedWork()</a></strong> function is to add a work item to a work queue after the configured delayed time. </p>
</td>
</tr>
<tr id="row1926735708165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p558114226165627"><a name="p558114226165627"></a><a name="p558114226165627"></a><a href="hdfworkqueue.md">HdfWorkQueue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1331469988165627"><a name="p1331469988165627"></a><a name="p1331469988165627"></a>Describes a work queue. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table774588886165627"></a>
<table><thead align="left"><tr id="row739123651165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2002989260165627"><a name="p2002989260165627"></a><a name="p2002989260165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1964342655165627"><a name="p1964342655165627"></a><a name="p1964342655165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row789747280165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477304033165627"><a name="p477304033165627"></a><a name="p477304033165627"></a><a href="driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5">HdfWorkFunc</a>) (void *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041856878165627"><a name="p2041856878165627"></a><a name="p2041856878165627"></a>typedef void(* </p>
<p id="p757402046165627"><a name="p757402046165627"></a><a name="p757402046165627"></a>Describes a work execution function type. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1895255102165627"></a>
<table><thead align="left"><tr id="row1524663758165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p120751686165627"><a name="p120751686165627"></a><a name="p120751686165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p192696116165627"><a name="p192696116165627"></a><a name="p192696116165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1199975627165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1235702054165627"><a name="p1235702054165627"></a><a name="p1235702054165627"></a>{ <a href="driverutils.md#ggac205be2172292384dd687b5471a87edda75df1ca644f77f78bf3539e356f2e446">HDF_WORK_BUSY_PENDING</a> = 1 &lt;&lt; 0, <a href="driverutils.md#ggac205be2172292384dd687b5471a87edda56532f81e262cca4680e754627d6dc44">HDF_WORK_BUSY_RUNNING</a> = 1 &lt;&lt; 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p880109468165627"><a name="p880109468165627"></a><a name="p880109468165627"></a>Enumerates statuses of a work item or a delayed work item. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1845386087165627"></a>
<table><thead align="left"><tr id="row1498115431165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1457747543165627"><a name="p1457747543165627"></a><a name="p1457747543165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1891382540165627"><a name="p1891382540165627"></a><a name="p1891382540165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row742055647165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p92519808165627"><a name="p92519808165627"></a><a name="p92519808165627"></a><a href="driverutils.md#gad7afae1dc691818c513094c873decabd">HdfWorkQueueInit</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue, char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1496407109165627"><a name="p1496407109165627"></a><a name="p1496407109165627"></a>int32_t </p>
<p id="p1584035279165627"><a name="p1584035279165627"></a><a name="p1584035279165627"></a>Initializes a work queue. </p>
</td>
</tr>
<tr id="row1170072931165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1896535382165627"><a name="p1896535382165627"></a><a name="p1896535382165627"></a><a href="driverutils.md#gad171adc8eda320fd01049a2b87ea62fb">HdfWorkInit</a> (<a href="hdfwork.md">HdfWork</a> *work, <a href="driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5">HdfWorkFunc</a> func, void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789422982165627"><a name="p1789422982165627"></a><a name="p1789422982165627"></a>int32_t </p>
<p id="p723949926165627"><a name="p723949926165627"></a><a name="p723949926165627"></a>Initializes a work item. </p>
</td>
</tr>
<tr id="row686918709165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766515097165627"><a name="p1766515097165627"></a><a name="p1766515097165627"></a><a href="driverutils.md#ga55bf669dc6740c65e4d45a4f641db2f1">HdfDelayedWorkInit</a> (<a href="hdfwork.md">HdfWork</a> *work, <a href="driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5">HdfWorkFunc</a> func, void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978504884165627"><a name="p1978504884165627"></a><a name="p1978504884165627"></a>int32_t </p>
<p id="p724761722165627"><a name="p724761722165627"></a><a name="p724761722165627"></a>Initializes a delayed work item. </p>
</td>
</tr>
<tr id="row1319719266165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1508152333165627"><a name="p1508152333165627"></a><a name="p1508152333165627"></a><a href="driverutils.md#gae6166caaf1b114e17834c50414b2d52e">HdfWorkDestroy</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p524894340165627"><a name="p524894340165627"></a><a name="p524894340165627"></a>void </p>
<p id="p461131704165627"><a name="p461131704165627"></a><a name="p461131704165627"></a>Destroys a work item. </p>
</td>
</tr>
<tr id="row553666656165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p574685452165627"><a name="p574685452165627"></a><a name="p574685452165627"></a><a href="driverutils.md#ga04ec328639aefd71683175e4c214fb80">HdfWorkQueueDestroy</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453249248165627"><a name="p453249248165627"></a><a name="p453249248165627"></a>void </p>
<p id="p2078891653165627"><a name="p2078891653165627"></a><a name="p2078891653165627"></a>Destroys a work queue. </p>
</td>
</tr>
<tr id="row1359039255165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081594415165627"><a name="p1081594415165627"></a><a name="p1081594415165627"></a><a href="driverutils.md#gaaaced5c0365d1a1232167b738f08b5ce">HdfDelayedWorkDestroy</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p431961539165627"><a name="p431961539165627"></a><a name="p431961539165627"></a>void </p>
<p id="p2070712743165627"><a name="p2070712743165627"></a><a name="p2070712743165627"></a>Destroys a delayed work item. </p>
</td>
</tr>
<tr id="row1218078147165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117062715165627"><a name="p117062715165627"></a><a name="p117062715165627"></a><a href="driverutils.md#ga82cc68d656aa17317634b07d49dae160">HdfAddWork</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue, <a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1321714118165627"><a name="p1321714118165627"></a><a name="p1321714118165627"></a>bool </p>
<p id="p832268590165627"><a name="p832268590165627"></a><a name="p832268590165627"></a>Adds a work item to a work queue. </p>
</td>
</tr>
<tr id="row1295975641165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1165978577165627"><a name="p1165978577165627"></a><a name="p1165978577165627"></a><a href="driverutils.md#gaef781ccc1579db3070745088da47b2c5">HdfAddDelayedWork</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue, <a href="hdfwork.md">HdfWork</a> *work, unsigned long ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550583424165627"><a name="p550583424165627"></a><a name="p550583424165627"></a>bool </p>
<p id="p637835806165627"><a name="p637835806165627"></a><a name="p637835806165627"></a>Adds a delayed work item to a work queue. </p>
</td>
</tr>
<tr id="row709662300165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1340594829165627"><a name="p1340594829165627"></a><a name="p1340594829165627"></a><a href="driverutils.md#ga37595ed36b8ce7be84c914aebfd99d00">HdfWorkBusy</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p515817583165627"><a name="p515817583165627"></a><a name="p515817583165627"></a>unsigned int </p>
<p id="p1109743894165627"><a name="p1109743894165627"></a><a name="p1109743894165627"></a>Obtains the status of a work item or delayed work item. </p>
</td>
</tr>
<tr id="row729973105165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2003304338165627"><a name="p2003304338165627"></a><a name="p2003304338165627"></a><a href="driverutils.md#gaab300487bdb9f3496bb823c657275dd3">HdfCancelWorkSync</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p726185122165627"><a name="p726185122165627"></a><a name="p726185122165627"></a>bool </p>
<p id="p668377380165627"><a name="p668377380165627"></a><a name="p668377380165627"></a>Cancels a work item. This function waits until the work item is complete. </p>
</td>
</tr>
<tr id="row1656761337165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1801400206165627"><a name="p1801400206165627"></a><a name="p1801400206165627"></a><a href="driverutils.md#gad53e46938809200db3caafdc85decc5a">HdfCancelDelayedWorkSync</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2123274541165627"><a name="p2123274541165627"></a><a name="p2123274541165627"></a>bool </p>
<p id="p1054333556165627"><a name="p1054333556165627"></a><a name="p1054333556165627"></a>Cancels a delayed work item. </p>
</td>
</tr>
</tbody>
</table>

