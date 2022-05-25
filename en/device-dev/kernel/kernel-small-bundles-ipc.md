# LiteIPC


## Basic Concepts<a name="section1980994712918"></a>

LiteIPC is a new inter-process communication \(IPC\) mechanism provided by the OpenHarmony LiteOS-A kernel. Different from the traditional System V IPC, LiteIPC is designed for Remote Procedure Call \(RPC\). In addition, it provides APIs for the upper layer through device files, not through traditional API functions.

LiteIPC has two important concepts: ServiceManager and Service. The entire system can have one ServiceManager and multiple Services. ServiceManager is responsible for registering and unregistering Services, and managing Service access permission \(only authorized tasks can send IPC messages to corresponding Services\).

## Working Principles<a name="section849811592918"></a>

ServiceManager registers the task that needs to receive IPC messages as a Service, and sets the access permission for the Service task \(specifies the tasks that can send IPC messages to the Service\). LiteIPC maintains an IPC message queue for each Service task in kernel mode. The message queue provides the upper-layer user-mode programs with the read operation \(receiving IPC messages\) and the write operations \(sending IPC messages\) through LiteIPC device files.

## Development Guidelines<a name="section17571315171017"></a>

### Available APIs<a name="section725022011103"></a>

**Table  1**  LiteIPC module APIs \(for LiteOS-A internal use only\)

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p8866127195914"><a name="p8866127195914"></a><a name="p8866127195914"></a>Module initialization</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p58621910185914"><a name="p58621910185914"></a><a name="p58621910185914"></a>OsLiteIpcInit</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p48623102592"><a name="p48623102592"></a><a name="p48623102592"></a>Initializes the LiteIPC module.</p>
</td>
</tr>
<tr id="row1213865218584"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p1219312239566"><a name="p1219312239566"></a><a name="p1219312239566"></a>IPC message memory pool</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p20862510115911"><a name="p20862510115911"></a><a name="p20862510115911"></a>LiteIpcPoolInit</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1886211011599"><a name="p1886211011599"></a><a name="p1886211011599"></a>Initializes the IPC message memory pool of processes.</p>
</td>
</tr>
<tr id="row3231257145813"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3313428135414"><a name="p3313428135414"></a><a name="p3313428135414"></a>LiteIpcPoolReInit</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p586261085913"><a name="p586261085913"></a><a name="p586261085913"></a>Re-initializes the IPC message memory pool of processes.</p>
</td>
</tr>
<tr id="row73651459105815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p464344145411"><a name="p464344145411"></a><a name="p464344145411"></a>LiteIpcPoolDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p555221518598"><a name="p555221518598"></a><a name="p555221518598"></a>Releases the IPC message memory pool of processes.</p>
</td>
</tr>
<tr id="row178321454145812"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p19527545175517"><a name="p19527545175517"></a><a name="p19527545175517"></a>Service management</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p756845455415"><a name="p756845455415"></a><a name="p756845455415"></a>LiteIpcRemoveServiceHandle</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1555261595915"><a name="p1555261595915"></a><a name="p1555261595915"></a>Deletes the specified Service.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>LiteIPC module APIs are used for LiteOS-A internal use only.

