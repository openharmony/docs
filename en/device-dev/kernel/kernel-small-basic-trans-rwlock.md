# RW Lock


## Basic Concepts

Similar to a mutex, a read-write lock (RW lock) can be used to synchronize tasks in the same process. Different from a mutex, an RW lock allows concurrent access for read operations and exclusive access for write operations.

An RW lock has three states: locked in read mode, locked in write mode, and unlocked.

Observe the following rules when using RW locks:

- If there is no lock in write mode in the protected area, any task can add a lock in read mode.

- A lock in write mode can be added only when the protected area is in the unlocked state.

In a multi-task environment, multiple tasks may access the same shared resource. A lock in read mode allows access to a protected area in shared mode, and a lock in a write mode allows exclusive access to the shared resource.

This sharing-exclusive manner is suitable for a multi-task environment where the data read operations are far more than data write operations. It can improve multi-task concurrency of the application.


## Working Principles

How does an RW lock implement lock in read mode and lock in write mode to control read/write access of multiple tasks?

- If task A acquires the lock in write mode for the first time, other tasks cannot acquire or attempt to acquire the lock in read mode.

- If task A acquires the lock in read mode, the RW lock count increments by 1 when a task acquires or attempts to acquire the lock in read mode.


## Development Guidelines


### Available APIs

**Table 1** APIs of the RW lock module

| API| Description|
| -------- | -------- |
| LOS_RwlockInit| Creates an RW lock.|
| LOS_RwlockDestroy| Deletes an RW lock.|
| LOS_RwlockRdLock| Requests the specified lock in read mode.|
| LOS_RwlockTryRdLock| Attempts to request a lock in read mode.|
| LOS_RwlockWrLock| Requests the specified lock in write mode.|
| LOS_RwlockTryWrLock| Attempts to request a lock in write mode.|
| LOS_RwlockUnLock| Releases the specified RW lock.|
| LOS_RwlockIsValid| Checks the validity of an RW lock.|


### How to Develop

The typical development process is as follows: 

1. Call **LOS_RwlockInit** to create an RW lock.

2. Call **LOS_RwlockRdLock** to request a lock in read mode or call **LOS_RwlockWrLock** to request a lock in write mode.

   If a lock in read mode is requested:

   - If the lock is not held, the read task can acquire the lock.

   - If the lock is held, the read task acquires the lock and is executed based on the task priority.

   - If the lock in write mode is held by another task, the task cannot acquire the lock until the lock in write mode is released.

   If a lock in write mode is requested:

   - If the lock is not held or if the task that holds the lock in read mode is the one that requests the lock in write mode, the task acquires the lock in write mode immediately.

   - If the lock already has a lock in read mode and the read task has a higher priority, the current task is suspended until the lock in read mode is released.

3. There are three types of locks in read mode and write mode: non-block mode, permanent block mode, and scheduled block mode. The difference lies in the task suspension time.

4. Call **LOS_RwlockUnLock** to release an RW lock.

   - If tasks are blocked by the specified RW lock, the task with the highest priority is woken up, enters the Ready state, and is scheduled.
   - If no task is blocked by the specified RW lock, the RW lock is released.

5. Call **LOS_RwlockDestroy** to delete an RW lock.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
   > - The RW lock cannot be used in the interrupt service program.
   > 
   > - The LiteOS-A kernel used in the RTOS must ensure real-time task scheduling and avoid long-time task blocking. Therefore, RW locks must be released as soon as possible after use.
   > 
   > - When an RW lock is held by a task, the task priority cannot be changed by using APIs, such as **LOS_TaskPriSet**.
