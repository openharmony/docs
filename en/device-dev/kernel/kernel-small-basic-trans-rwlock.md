# RW Lock


## Basic Concepts<a name="section4692105214260"></a>

Similar to a mutex, a read-write lock \(RW lock\) can be used to synchronize tasks in the same process. Different from a mutex, an RW lock allows concurrent access for read operations and exclusive access for write operations.

An RW lock has three states: locked in read mode, locked in write mode, and unlocked.

Observe the following rules when using RW locks:

-   If there is no lock in write mode in the protected area, any task can add a lock in read mode.
-   A lock in write mode can be added only when the protected area is in the unlocked state.

In a multi-task environment, multiple tasks may access the same shared resource. A lock in read mode allows access to a protected area in shared mode, and a lock in a write mode allows exclusive access to the shared resource.

This sharing-exclusive manner is suitable for a multi-task environment where the data read operations are far more than data write operations. It can improve multi-task concurrency of the application.

## Working Principles<a name="section1239111562720"></a>

How does an RW lock implement lock in read mode and lock in write mode to control read/write access of multiple tasks?

-   If task A acquires the lock in write mode for the first time, other tasks cannot acquire or attempt to acquire the lock in read mode.

-   If task A acquires the lock in read mode, the RW lock count increments by 1 when a task acquires or attempts to acquire the lock in read mode.

## Development Guidelines<a name="section11643194275"></a>

### Available APIs<a name="section15335332122717"></a>

**Table  1**  Read/write lock module APIs

<a name="table37108292611"></a>
<table><thead align="left"><tr id="row8711112919610"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p3711102912617"><a name="p3711102912617"></a><a name="p3711102912617"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1671110293610"><a name="p1671110293610"></a><a name="p1671110293610"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p87114292617"><a name="p87114292617"></a><a name="p87114292617"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row37115291166"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1795312108911"><a name="p1795312108911"></a><a name="p1795312108911"></a>Creating and deleting an RW lock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1671120293611"><a name="p1671120293611"></a><a name="p1671120293611"></a>LOS_RwlockInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p171112291967"><a name="p171112291967"></a><a name="p171112291967"></a>Creates an RW lock.</p>
</td>
</tr>
<tr id="row17711329268"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p071114291864"><a name="p071114291864"></a><a name="p071114291864"></a>LOS_RwlockDestroy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p137111129965"><a name="p137111129965"></a><a name="p137111129965"></a>Deletes the specified RW lock.</p>
</td>
</tr>
<tr id="row5711192912616"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p86087143910"><a name="p86087143910"></a><a name="p86087143910"></a>Requesting a lock in read mode</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1171112295614"><a name="p1171112295614"></a><a name="p1171112295614"></a>LOS_RwlockRdLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1271110291969"><a name="p1271110291969"></a><a name="p1271110291969"></a>Requests the specified lock in read mode.</p>
</td>
</tr>
<tr id="row1571162918615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1564192618292"><a name="p1564192618292"></a><a name="p1564192618292"></a>LOS_RwlockTryRdLock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107118291660"><a name="p107118291660"></a><a name="p107118291660"></a>Attempts to request the specified lock in read mode.</p>
</td>
</tr>
<tr id="row189551130172817"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p7951153082815"><a name="p7951153082815"></a><a name="p7951153082815"></a>Requesting a lock in write mode</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p111591404308"><a name="p111591404308"></a><a name="p111591404308"></a>LOS_RwlockWrLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11951183013281"><a name="p11951183013281"></a><a name="p11951183013281"></a>Requests the specified lock in write mode.</p>
</td>
</tr>
<tr id="row199551530122820"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p32171573014"><a name="p32171573014"></a><a name="p32171573014"></a>LOS_RwlockTryWrLock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5951123092819"><a name="p5951123092819"></a><a name="p5951123092819"></a>Attempts to request the specified lock in write mode.</p>
</td>
</tr>
<tr id="row1642820328301"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1542823210305"><a name="p1542823210305"></a><a name="p1542823210305"></a>Releasing an RW lock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p174281324308"><a name="p174281324308"></a><a name="p174281324308"></a>LOS_RwlockUnLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1342810327309"><a name="p1342810327309"></a><a name="p1342810327309"></a>Releases the specified RW lock.</p>
</td>
</tr>
<tr id="row11318134133111"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p73182345312"><a name="p73182345312"></a><a name="p73182345312"></a>Verifying RW lock validity</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1031813416318"><a name="p1031813416318"></a><a name="p1031813416318"></a>LOS_RwlockIsValid</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p43187342311"><a name="p43187342311"></a><a name="p43187342311"></a>Checks the validity of an RW lock.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section14774114882714"></a>

The typical development process is as follows: 

1. Call  **LOS\_RwlockInit**  to create an RW lock.

2. Call  **LOS\_RwlockRdLock**  to request a lock in read mode or call  **LOS\_RwlockWrLock**  to request a lock in write mode.

If a lock in read mode is requested:

-   If the lock is not held, the read task can acquire the lock.
-   If the lock is held, the read task acquires the lock and is executed based on the task priority.
-   If the lock in write mode is held by another task, the task cannot acquire the lock until the lock in write mode is released.

If a lock in write mode is requested:

-   If the lock is not held or if the task that holds the lock in read mode is the one that requests the lock in write mode, the task acquires the lock in write mode immediately.
-   If the lock already has a lock in read mode and the read task has a higher priority, the current task is suspended until the lock in read mode is released.

3. There are three types of locks in read mode and write mode: non-block mode, permanent block mode, and scheduled block mode. The difference lies in the task suspension time.

4. Call  **LOS\_RwlockUnLock**  to release an RW lock.

-   If tasks are blocked by the specified RW lock, the task with the highest priority is woken up, enters the Ready state, and is scheduled.

-   If no task is blocked by the specified RW lock, the RW lock is released.

5. Call  **LOS\_RwlockDestroy**  to delete an RW lock.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The RW lock cannot be used in the interrupt service program.
>-   When using the LiteOS-A kernel, the OpenHarmony must ensure real-time task scheduling and avoid long-time task blocking. Therefore, an RW lock must be released as soon as possible after use.
>-   When an RW lock is held by a task, the task priority cannot be changed by using APIs such as  **LOS\_TaskPriSet**.

