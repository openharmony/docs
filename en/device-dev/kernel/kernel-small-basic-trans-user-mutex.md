# Futex


## Basic Concepts<a name="section643519912920"></a>

Fast userspace mutex \(futex\) is a system call capability provided by the kernel. It is a basic component that combines with user-mode lock logic to form a user-mode lock. It is a lock working in both user mode and kernel mode, for example, userspace mutex, barrier and cond synchronization lock, and RW lock. The user-mode part implements lock logic, and the kernel-mode part schedules locks.

When a user-mode thread requests a lock, the lock status is first checked in user space. If no lock contention occurs, the user-mode thread acquires the lock directly. If lock contention occurs, the futex system call is invoked to request the kernel to suspend the thread and maintain the blocking queue.

When a user-mode thread releases a lock, the lock status is first checked in user space. If no other thread is blocked by the lock, the lock is directly released in user space. If there are threads blocked by the lock, the futex system call is invoked to request the kernel to wake up the threads in the blocking queue.

## Working Principles<a name="section16834132502910"></a>

When thread scheduling is required to resolve lock contention or lock release in user space, the futex system call is invoked to pass the user-mode lock address to the kernel. The user-mode locks are distinguished by lock address in the futex of the kernel. The available virtual address space in user space is 1 GiB. To facilitate search and management of lock addresses, the kernel futex uses hash buckets to store the user-mode locks.

There are 80 hash buckets. Buckets 0 to 63 are used to store private locks \(hashed based on virtual addresses\), and buckets 64 to 79 are used to store shared locks \(hashed based on physical addresses\). The private/shared attributes are determined by initialization of user-mode locks and the input parameters in the futex system call.

**Figure  1**  Futex design<a name="fig651353710598"></a>  
![](figures/futex-design.jpg "futex-design")

As shown in the above figure, each futex hash bucket stores the futex nodes with the same hash value linked in a futex\_list. Each futex node corresponds to a suspended task. The key value of a node uniquely identifies a user-mode lock. The nodes with the same key value added to a queue\_list indicate a queue of tasks blocked by the same lock.

The following table describes the APIs available for the futex module.

**Table  1**  Futex module APIs

<a name="table1316220185211"></a>
<table><thead align="left"><tr id="row191622182021"><th class="cellrowborder" valign="top" width="27.09270927092709%" id="mcps1.2.4.1.1"><p id="p13162121815218"><a name="p13162121815218"></a><a name="p13162121815218"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="26.52265226522652%" id="mcps1.2.4.1.2"><p id="p12162618623"><a name="p12162618623"></a><a name="p12162618623"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="46.384638463846386%" id="mcps1.2.4.1.3"><p id="p16162118427"><a name="p16162118427"></a><a name="p16162118427"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row04981218910"><td class="cellrowborder" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p6462616696"><a name="p6462616696"></a><a name="p6462616696"></a>Putting a thread to wait</p>
</td>
<td class="cellrowborder" valign="top" width="26.52265226522652%" headers="mcps1.2.4.1.2 "><p id="p164931214913"><a name="p164931214913"></a><a name="p164931214913"></a>OsFutexWait</p>
</td>
<td class="cellrowborder" valign="top" width="46.384638463846386%" headers="mcps1.2.4.1.3 "><p id="p8504121996"><a name="p8504121996"></a><a name="p8504121996"></a>Inserts a node representing a blocked thread into the futex list.</p>
</td>
</tr>
<tr id="row7162101814216"><td class="cellrowborder" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p37331032985"><a name="p37331032985"></a><a name="p37331032985"></a>Waking up a thread</p>
</td>
<td class="cellrowborder" valign="top" width="26.52265226522652%" headers="mcps1.2.4.1.2 "><p id="p816311185217"><a name="p816311185217"></a><a name="p816311185217"></a>OsFutexWake</p>
</td>
<td class="cellrowborder" valign="top" width="46.384638463846386%" headers="mcps1.2.4.1.3 "><p id="p161632181721"><a name="p161632181721"></a><a name="p161632181721"></a>Wakes up a thread that is blocked by a specified lock.</p>
</td>
</tr>
<tr id="row101631818620"><td class="cellrowborder" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p146111936887"><a name="p146111936887"></a><a name="p146111936887"></a>Modifying the lock address</p>
</td>
<td class="cellrowborder" valign="top" width="26.52265226522652%" headers="mcps1.2.4.1.2 "><p id="p71633181125"><a name="p71633181125"></a><a name="p71633181125"></a>OsFutexRequeue</p>
</td>
<td class="cellrowborder" valign="top" width="46.384638463846386%" headers="mcps1.2.4.1.3 "><p id="p151631718124"><a name="p151631718124"></a><a name="p151631718124"></a>Adjusts the position of a specified lock in the futex list.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The futex system call and user-mode logic form a user-mode lock. Therefore, you are advised to use the locks via the user-mode POSIX APIs.

