# Process


## Basic Concepts<a name="section89346055119"></a>

A process is the minimum unit for system resource management. The process module provided by the OpenHarmony LiteOS-A kernel is used to isolate user-mode processes. The kernel mode is considered as a process space and does not have other processes except KIdle, which is an idle process provided by the system and shares the same process space with KProcess.

-   The process module provides multiple processes for users and implements switching and communication between processes, facilitating your management over service programs.
-   The processes use the preemption scheduling mechanism. The processes with a higher priority are scheduled first, and the processes with the same priority are scheduled using the time slice polling.
-   The processes are assigned 32 priorities \(**0**  to  **31**\). Among them, user processes can be configured with 22 priorities from  **10**  \(highest\) to  **31**  \(lowest\).
-   A higher-priority process can preempt the resources of a lower-priority process. The lower-priority process can be scheduled only after the higher-priority process is blocked or terminated.
-   Each user-mode process has its own memory space, which is invisible to other processes. In this way, processes are isolated from each other.
-   The user-mode root process  **init**  is created by the kernel. Other user-mode processes are created by the  **init**  process via the  **fork**  call.

**Process States:**

-   Init: The process is being created.

-   Ready: The process is in the Ready queue and waits for scheduling by the CPU.
-   Running: The process is running.
-   Pending: The process is blocked and suspended. When all threads in a process are blocked, the process is blocked and suspended.
-   Zombies: The process stops running and waits for the parent process to reclaim its control block resources.

**Figure  1**  Process state transition<a name="fig536823565718"></a>  
![](figures/process-state-transition.png "process-state-transition")

**Process State Transition:**

-   Init→Ready:

    When a process is created, the process enters the Init state after obtaining the process control block to start initialization. After the process is initialized, the process is inserted into the scheduling queue and therefore enters the Ready state.

-   Ready→Running:

    When a process switchover is triggered, the process with the highest priority in the Ready queue is executed and enters the Running state. If this process has no thread in the Ready state, the process is deleted from the Ready queue and resides only in the Running state. If it has threads in the Ready state, the process still stays in the Ready queue. In this case, the process is in both the Ready and Running states, but presented as the Running state.

-   Running→Pending:

    When the last thread of a process enters the Pending state, all threads in the process are in the Pending state. Then, the process enters the Pending state, and process switching occurs.

-   Pending→Ready:

    When any thread in a Pending process restores to the Ready state, the process is added to the Ready queue and changes to the Ready state.

-   Ready→Pending:

    When the last ready thread in a process enters the Pending state, the process is deleted from the Ready queue, and the process changes from the Ready state to the Pending state.

-   Running→Ready:

    A process may change from the Running state to the Ready state in either of the following scenarios:

    1.  After a process with a higher priority is created or restored, processes will be scheduled. The process with the highest priority in the Ready queue will change to the Running state, and the originally running process will change from the Running state to the Ready state.
    2.  If scheduling policy for a process is  **LOS\_SCHED\_RR**  and its priority is the same as that of another process in the Ready state, this process will change from the Running state to the Ready state after its time slices are used up, and the other process with the same priority will change from the Ready state to the Running state.

-   Running→Zombies:

    After the main thread or all threads of a process are stopped, the process changes from the  **Running**  state to the  **Zombies**  state and waits for the parent process to reclaim resources.


## Working Principles<a name="section174514474512"></a>

The OpenHarmony process module is used to isolate user-mode processes and supports the following functions: creating and exiting user-mode processes, reclaiming process resources, setting and obtaining scheduling parameters and process group IDs, and obtaining process IDs.

A user-mode process is created by forking a parent process. During forking, the virtual memory space of the parent process is cloned to the child process. When the child process is running, the content of the parent process is copied to the virtual memory space of the child process as required through the copy-on-write mechanism.

A process is only a resource management unit, and the actual running is executed by threads in the process. When switching occurs between threads in different processes, the process space will be switched.

**Figure  2**  Process management<a name="fig123709256334"></a>  
![](figures/process-management.png "process-management")

## Development Guidelines<a name="section159637182521"></a>

### Available APIs<a name="section1153124135212"></a>

**Table  1**  Process management module APIs

<a name="table359914125718"></a>
<table><thead align="left"><tr id="row85991712770"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p13162121815218"><a name="p13162121815218"></a><a name="p13162121815218"></a><strong id="b1498913473"><a name="b1498913473"></a><a name="b1498913473"></a>Function</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p12162618623"><a name="p12162618623"></a><a name="p12162618623"></a><strong id="b3249144342911"><a name="b3249144342911"></a><a name="b3249144342911"></a>API</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p16162118427"><a name="p16162118427"></a><a name="p16162118427"></a><strong id="b1858304911219"><a name="b1858304911219"></a><a name="b1858304911219"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row66002121074"><td class="cellrowborder" rowspan="4" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p13571544484"><a name="p13571544484"></a><a name="p13571544484"></a>Process scheduling parameter control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p7571644283"><a name="p7571644283"></a><a name="p7571644283"></a>LOS_GetProcessScheduler</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p205724410813"><a name="p205724410813"></a><a name="p205724410813"></a>Obtains the scheduling policy of the specified process.</p>
</td>
</tr>
<tr id="row166001712574"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6571144286"><a name="p6571144286"></a><a name="p6571144286"></a>LOS_SetProcessScheduler</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18572443819"><a name="p18572443819"></a><a name="p18572443819"></a>Sets the scheduling parameters, including the priority and scheduling policy, for the specified process.</p>
</td>
</tr>
<tr id="row1560071212719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3571144885"><a name="p3571144885"></a><a name="p3571144885"></a>LOS_GetProcessPriority</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p95710448818"><a name="p95710448818"></a><a name="p95710448818"></a>Obtains the priority of the specified process.</p>
</td>
</tr>
<tr id="row1274011131587"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17572443812"><a name="p17572443812"></a><a name="p17572443812"></a>LOS_SetProcessPriority</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16573445819"><a name="p16573445819"></a><a name="p16573445819"></a>Sets the priority of the specified process.</p>
</td>
</tr>
<tr id="row162882182816"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p175734417814"><a name="p175734417814"></a><a name="p175734417814"></a>Waiting for reclaiming child processes</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p165754410812"><a name="p165754410812"></a><a name="p165754410812"></a>LOS_Wait</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5578441687"><a name="p5578441687"></a><a name="p5578441687"></a>Waits for the specified child process to terminate, and reclaims its resources.</p>
</td>
</tr>
<tr id="row81051920589"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4571844289"><a name="p4571844289"></a><a name="p4571844289"></a>Process group</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p20578442083"><a name="p20578442083"></a><a name="p20578442083"></a>LOS_GetProcessGroupID</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p145704416818"><a name="p145704416818"></a><a name="p145704416818"></a>Obtains the process group ID of the specified process.</p>
</td>
</tr>
<tr id="row13410161611819"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p657944289"><a name="p657944289"></a><a name="p657944289"></a>LOS_GetCurrProcessGroupID</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p165816445819"><a name="p165816445819"></a><a name="p165816445819"></a>Obtains the process group ID of the current process.</p>
</td>
</tr>
<tr id="row1260011213718"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p125818441781"><a name="p125818441781"></a><a name="p125818441781"></a>Obtaining the process ID.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p25814445819"><a name="p25814445819"></a><a name="p25814445819"></a>LOS_GetCurrProcessID</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1058644687"><a name="p1058644687"></a><a name="p1058644687"></a>Obtains the ID of the current process.</p>
</td>
</tr>
<tr id="row060019121871"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p145810441285"><a name="p145810441285"></a><a name="p145810441285"></a>User and user group</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10581744783"><a name="p10581744783"></a><a name="p10581744783"></a>LOS_GetUserID</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7581944287"><a name="p7581944287"></a><a name="p7581944287"></a>Obtains the user ID of the current process.</p>
</td>
</tr>
<tr id="row1160021211713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18582447814"><a name="p18582447814"></a><a name="p18582447814"></a>LOS_GetGroupID</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3581444382"><a name="p3581444382"></a><a name="p3581444382"></a>Obtains the user group ID of the current process.</p>
</td>
</tr>
<tr id="row1160018123717"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19589442084"><a name="p19589442084"></a><a name="p19589442084"></a>LOS_CheckInGroups</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5581144689"><a name="p5581144689"></a><a name="p5581144689"></a>Checks whether the specified user group ID is in the user group of the current process.</p>
</td>
</tr>
<tr id="row317461111812"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p105814419818"><a name="p105814419818"></a><a name="p105814419818"></a>Maximum number of processes supported</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p3583441888"><a name="p3583441888"></a><a name="p3583441888"></a>LOS_GetSystemProcessMaximum</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p115818441187"><a name="p115818441187"></a><a name="p115818441187"></a>Obtains the maximum number of processes supported by the system.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section1533674618526"></a>

Kernel-mode processes cannot be created. Therefore, kernel-mode process development is not involved.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The number of idle threads depends on the number of CPU cores. Each CPU has a corresponding idle thread.
>-   Except KProcess and KIdle, other kernel-mode processes cannot be created.
>-   If a thread is created after a user-mode process enters the kernel mode by a system call, the thread belongs to a KProcess not a user-mode process.

