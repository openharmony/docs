# Scheduler


## Basic Concepts<a name="section123882355719"></a>

The OpenHarmony LiteOS-A kernel uses the preemptive scheduling mechanism for tasks. The tasks with a higher priority are scheduled first, and the tasks with the same priority are scheduled using the time slice polling. The system runs based on the real-time timeline from the startup, which ensures good real-time performance of the scheduling algorithm.

The OpenHarmony scheduling algorithm is embedded with the tickless mechanism, which ensures lower power consumption and on-demand response to tick interrupts. This minimizes useless tick interrupt response time and further improves the real-time performance of the system.

The OpenHarmony process scheduling policy is  **SCHED\_RR**, and the thread scheduling policy can be  **SCHED\_RR**  or  **SCHED\_FIFO**.

Threads are the minimum scheduling units in the OpenHarmony.

## Working Principles<a name="section143015396572"></a>

The OpenHarmony uses process priority queue and thread priority queue for scheduling. The process priority ranges from 0 to 31, and there are 32 process priority bucket queues. Each bucket queue corresponds to a thread priority bucket queue. The thread priority ranges from 0 to 31, and a thread priority bucket queue also has 32 priority queues.

**Figure  1**  Scheduling priority bucket queue<a name="fig124425991619"></a>  
![](figures/scheduling-priority-bucket-queue.png "scheduling-priority-bucket-queue")

The OpenHarmony system starts scheduling after the kernel initialization is complete. The processes or threads created during running are added to the scheduling queues. The system selects the optimal thread for scheduling based on the priorities of the processes and threads and the time slice consumption of the threads. Once a thread is scheduled, it is deleted from the scheduling queue. If a thread is blocked during running, the thread is added to the corresponding blocking queue and triggers scheduling of another thread. If no thread in the scheduling queue can be scheduled, the system selects the thread of the KIdle process for scheduling.

**Figure  2**  Scheduling process<a name="fig1163494931810"></a>  
![](figures/scheduling-process.png "scheduling-process")

## Development Guidelines<a name="section10604192145816"></a>

### Available APIs<a name="section207985910582"></a>

<a name="table687929113814"></a>
<table><thead align="left"><tr id="row513082983812"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p121309298384"><a name="p121309298384"></a><a name="p121309298384"></a><strong id="b1684811125913"><a name="b1684811125913"></a><a name="b1684811125913"></a>Function</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p713082933817"><a name="p713082933817"></a><a name="p713082933817"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p20130829123810"><a name="p20130829123810"></a><a name="p20130829123810"></a><strong id="b66639257454"><a name="b66639257454"></a><a name="b66639257454"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row713032973813"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p0130429133818"><a name="p0130429133818"></a><a name="p0130429133818"></a>System scheduling</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p71581556124414"><a name="p71581556124414"></a><a name="p71581556124414"></a>LOS_Schedule</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p181303297387"><a name="p181303297387"></a><a name="p181303297387"></a>Triggers system scheduling.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section1015110331584"></a>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>Scheduling cannot be triggered during the system initialization process.

