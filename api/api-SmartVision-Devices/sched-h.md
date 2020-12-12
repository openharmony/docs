# sched.h<a name="ZH-CN_TOPIC_0000001055547982"></a>

-   [Overview](#section1489964204165629)
-   [Summary](#section1760415800165629)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1489964204165629"></a>

**Related Modules:**

[PROCESS](PROCESS.md)

**Description:**

Provides process- and thread-related structures and functions \(for example, obtaining scheduling policies and parameters\). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1760415800165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table377259730165629"></a>
<table><thead align="left"><tr id="row286067515165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1033609976165629"><a name="p1033609976165629"></a><a name="p1033609976165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1370939620165629"><a name="p1370939620165629"></a><a name="p1370939620165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row616190914165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p594838048165629"><a name="p594838048165629"></a><a name="p594838048165629"></a><a href="sched_param.md">sched_param</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236654840165629"><a name="p236654840165629"></a><a name="p236654840165629"></a>Defines process scheduling parameters. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table444697023165629"></a>
<table><thead align="left"><tr id="row1101212821165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1169378697165629"><a name="p1169378697165629"></a><a name="p1169378697165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2096954084165629"><a name="p2096954084165629"></a><a name="p2096954084165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row32048457165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1477997409165629"><a name="p1477997409165629"></a><a name="p1477997409165629"></a><a href="PROCESS.md#gafaebd1698caeb9b9b9e614ad84edd609">sched_get_priority_max</a> (int policy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p385491331165629"><a name="p385491331165629"></a><a name="p385491331165629"></a>int </p>
<p id="p903793062165629"><a name="p903793062165629"></a><a name="p903793062165629"></a>Obtains the maximum static priority that can be used for a process. </p>
</td>
</tr>
<tr id="row514904530165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1758478510165629"><a name="p1758478510165629"></a><a name="p1758478510165629"></a><a href="PROCESS.md#gaf1f370fc36ea6b22ed42b5ee3cf82a81">sched_get_priority_min</a> (int policy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p154808339165629"><a name="p154808339165629"></a><a name="p154808339165629"></a>int </p>
<p id="p285795601165629"><a name="p285795601165629"></a><a name="p285795601165629"></a>Obtains the minimum static priority that can be used for a process. </p>
</td>
</tr>
<tr id="row130191386165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1896465007165629"><a name="p1896465007165629"></a><a name="p1896465007165629"></a><a href="PROCESS.md#ga563c7ac53bac2c1b51379147e66c44ec">sched_getparam</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614914525165629"><a name="p1614914525165629"></a><a name="p1614914525165629"></a>int </p>
<p id="p851225896165629"><a name="p851225896165629"></a><a name="p851225896165629"></a>Obtains scheduling parameters of a process. </p>
</td>
</tr>
<tr id="row267256268165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073770071165629"><a name="p1073770071165629"></a><a name="p1073770071165629"></a><a href="PROCESS.md#ga99fcb2532b1482d236dc04495a3f194d">sched_getscheduler</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p908861450165629"><a name="p908861450165629"></a><a name="p908861450165629"></a>int </p>
<p id="p322504552165629"><a name="p322504552165629"></a><a name="p322504552165629"></a>Obtains the scheduling policy of a process. </p>
</td>
</tr>
<tr id="row1891623718165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p163899483165629"><a name="p163899483165629"></a><a name="p163899483165629"></a><a href="PROCESS.md#ga484f0eb93529d29a66e24485725c4c7b">sched_rr_get_interval</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, struct <a href="timespec.md">timespec</a> *interval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1271981866165629"><a name="p1271981866165629"></a><a name="p1271981866165629"></a>int </p>
<p id="p1712698709165629"><a name="p1712698709165629"></a><a name="p1712698709165629"></a>Obtains the execution time limit of a process. </p>
</td>
</tr>
<tr id="row1141101146165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p165835402165629"><a name="p165835402165629"></a><a name="p165835402165629"></a><a href="PROCESS.md#ga06b497c4ea6bbabd2b62ba1a8a848a1b">sched_setparam</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1309755415165629"><a name="p1309755415165629"></a><a name="p1309755415165629"></a>int </p>
<p id="p1277154651165629"><a name="p1277154651165629"></a><a name="p1277154651165629"></a>Sets scheduling parameters related to a scheduling policy for a process. </p>
</td>
</tr>
<tr id="row1999985090165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p338950028165629"><a name="p338950028165629"></a><a name="p338950028165629"></a><a href="PROCESS.md#ga84ad29a6f2ad27370df09c664ac65eac">sched_setscheduler</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, int policy, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p342906975165629"><a name="p342906975165629"></a><a name="p342906975165629"></a>int </p>
<p id="p750408962165629"><a name="p750408962165629"></a><a name="p750408962165629"></a>Sets a scheduling policy for a process. </p>
</td>
</tr>
<tr id="row1585556163165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p832542445165629"><a name="p832542445165629"></a><a name="p832542445165629"></a><a href="PROCESS.md#ga357cd4b34c13011749dfffb42b489f09">sched_yield</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2106556279165629"><a name="p2106556279165629"></a><a name="p2106556279165629"></a>int </p>
<p id="p787889794165629"><a name="p787889794165629"></a><a name="p787889794165629"></a>Yields the running process. </p>
</td>
</tr>
</tbody>
</table>

