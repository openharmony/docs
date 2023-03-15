# Atomic Operation


## Basic Concepts

In an OS that supports multiple tasks, modifying data in memory involves three steps: read data, modify data, and write data. However, the data may be simultaneously accessed by multiple tasks. If the data modification is interrupted by another task, an unexpected result will be caused.

Although you can enable or disable interrupts to ensure expected results of multiple tasks, the system performance is affected.

The ARMv6 architecture has introduced the **LDREX** and **STREX** instructions to support more discreet non-blocking synchronization of the shared memory. The atomic operations implemented thereby can ensure that the "read-modify-write" operations on the same data will not be interrupted, that is, the operation atomicity is ensured.


## Working Principles

OpenHarmony has encapsulated the **LDREX** and **STREX** in the ARMv6 architecture to provide a set of atomic operation APIs.

- LDREX Rx, [Ry]
  Reads the value in the memory and marks the exclusive access to the memory segment.
  - Reads the 4-byte memory data pointed by the register **Ry** and saves the data to the **Rx** register.
  - Adds an exclusive access flag to the memory area pointed by **Ry**.

- STREX Rf, Rx, [Ry]
  Checks whether the memory has an exclusive access flag. If yes, the system updates the memory value and clears the flag. If no, the memory is not updated.
  - If there is an exclusive access flag, the system:
    - Updates the **Rx** register value to the memory pointed to by the **Ry** register.
    - Sets the **Rf** register to **0**.
  - If there is no exclusive access flag:
    - The memory is not updated.
    - The system sets the **Rf** register to **1**.

- Flag register
  - If the flag register is **0**, the system exits the loop and the atomic operation is complete.
  - If the flag register is **1**, the system continues the loop and performs the atomic operation again.


## Development Guidelines


### Available APIs

The following table describes the APIs available for the OpenHarmony LiteOS-A kernel atomic operation module.

**Table 1** APIs for atomic operations

| Category    | API           | Description                       |
| ------------ | ----------------------- | --------------------------- |
| Read          | LOS_AtomicRead          | Reads 32-bit atomic data.          |
| Read          | LOS_Atomic64Read        | Reads 64-bit atomic data.          |
| Write          | LOS_AtomicSet           | Sets 32-bit atomic data.          |
| Write          | LOS_Atomic64Set         | Sets 64-bit atomic data.          |
| Add          | LOS_AtomicAdd           | Adds 32-bit atomic data.      |
| Add          | LOS_Atomic64Add         | Adds 64-bit atomic data.      |
| Add          | LOS_AtomicInc           | Adds 1 to 32-bit atomic data.       |
| Add          | LOS_Atomic64Inc         | Adds 1 to 64-bit atomic data.       |
| Add          | LOS_AtomicIncRet        | Adds 1 to 32-bit atomic data and returns the data. |
| Add          | LOS_Atomic64IncRet      | Adds 1 to 64-bit atomic data and returns the data. |
| Subtract          | LOS_AtomicSub           | Performs subtraction on 32-bit atomic data.      |
| Subtract          | LOS_Atomic64Sub         | Performs subtraction on 64-bit atomic data.      |
| Subtract          | LOS_AtomicDec           | Subtracts 1 from 32-bit atomic data.       |
| Subtract          | LOS_Atomic64Dec         | Subtracts 1 from 64-bit atomic data.       |
| Subtract          | LOS_AtomicDecRet        | Subtracts 1 from 32-bit atomic data and returns the result. |
| Subtract          | LOS_Atomic64DecRet      | Subtracts 1 from 64-bit atomic data and returns the result. |
| Swap        | LOS_AtomicXchgByte      | Swaps 8-bit memory data.           |
| Swap        | LOS_AtomicXchg16bits    | Swaps 16-bit memory data.          |
| Swap        | LOS_AtomicXchg32bits    | Swaps 32-bit memory data.          |
| Swap        | LOS_AtomicXchg64bits    | Swaps 64-bit memory data.          |
| Compare and swap| LOS_AtomicCmpXchgByte   | Compares and swaps 8-bit memory data. |
| Compare and swap| LOS_AtomicCmpXchg16bits | Compares and swaps 16-bit memory data.|
| Compare and swap| LOS_AtomicCmpXchg32bits | Compares and swaps 32-bit memory data.|
| Compare and swap| LOS_AtomicCmpXchg64bits | Compares and swaps 64-bit memory data.|


### How to Develop

When multiple tasks perform addition, subtraction, and swap operations on the same memory data, use atomic operations to ensure predictability of results.

> **NOTE**<br>
>  Atomic operation APIs support only integers.


### Development Example

**Example Description**

Call the atomic operation APIs and observe the result.

1. Create two tasks.
   - Task 1: Call **LOS_AtomicInc** to add a global variable 100 times.
   - Task 2: Call **LOS_AtomicDec** to subtract a global variable 100 times.

2. After the subtasks are complete, print the values of the global variable in the main task.

**Sample Code**

The sample code is as follows:


```
#include "los_hwi.h"
#include "los_atomic.h"
#include "los_task.h"

UINT32 g_testTaskId01;
UINT32 g_testTaskId02;
Atomic g_sum;
Atomic g_count;

UINT32 Example_Atomic01(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicInc(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_Atomic02(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicDec(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_AtomicTaskEntry(VOID)
{
    TSK_INIT_PARAM_S stTask1={0};
    stTask1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic01;
    stTask1.pcName       = "TestAtomicTsk1";
    stTask1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask1.usTaskPrio   = 4;
    stTask1.uwResved     = LOS_TASK_STATUS_DETACHED;

    TSK_INIT_PARAM_S stTask2={0};
    stTask2.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic02;
    stTask2.pcName       = "TestAtomicTsk2";
    stTask2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask2.usTaskPrio   = 4;
    stTask2.uwResved     = LOS_TASK_STATUS_DETACHED;

    LOS_TaskLock();
    LOS_TaskCreate(&g_testTaskId01, &stTask1);
    LOS_TaskCreate(&g_testTaskId02, &stTask2);
    LOS_TaskUnlock();

    while(LOS_AtomicRead(&g_count) != 2);
    PRINTK("g_sum = %d\n", g_sum);

    return LOS_OK;
}
```

**Verification**


```
g_sum = 0
```
