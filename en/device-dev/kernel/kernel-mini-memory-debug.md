# Memory Debugging


The purpose of memory debugging is to locate problems related to dynamic memory. The kernel provides a variety of memory debugging methods. Dynamic memory pool statistics helps you learn the memory pool waterline and fragmentation rate. Memory leak check helps you accurately locate the code where memory leak occurs and analyze the memory usage of each module. Memory corruption check helps you locate memory corruptions.


## Memory Information Statistics


### Basic Concepts

Memory information includes the memory pool size, memory usage, remaining memory size, maximum free memory, memory waterline, number of memory nodes, and fragmentation rate.

- Memory waterline indicates the maximum memory used in a memory pool. The waterline value is updated upon each memory allocation and release. The memory pool size can be optimized based on this value.

- Fragmentation rate indicates the fragmentation degree of the memory pool. If the fragmentation rate is high, there are a large number of free memory blocks in the memory pool but each block is small. You can use the following formula to calculate the fragmentation rate:<br>Fragmentation rate = 100 – 100 x Maximum free memory block size/Remaining memory size

- You can use [APIs for memory management](kernel-mini-basic-memory.md) to scan node information in the memory pool and collect statistics.


### Function Configuration

**LOSCFG_MEM_WATERLINE** specifies the setting of the memory information statistics function. This function is enabled by default. To disable the function, set this macro to **0** in **target_config.h**. If you want to obtain the memory waterline, you must enable this macro.


### Development Guidelines


#### How to Develop

Key structure:


```
typedef struct {
    UINT32 totalUsedSize;       // Memory usage of the memory pool.
    UINT32 totalFreeSize;       // Remaining size of the memory pool.
    UINT32 maxFreeNodeSize;     // Maximum size of the free memory block in the memory pool.
    UINT32 usedNodeNum;         // Number of non-free memory blocks in the memory pool.
    UINT32 freeNodeNum;         // Number of free memory blocks in the memory pool.
#if (LOSCFG_MEM_WATERLINE == 1) // The function is enabled by default. To disable it, set this macro to 0 in target_config.h.
    UINT32 usageWaterLine;      // Waterline of the memory pool.
#endif
} LOS_MEM_POOL_STATUS;
```

To obtain the memory waterline, call **LOS_MemInfoGet**. The first parameter in the API is the start address of the memory pool, and the second parameter is the handle of the **LOS_MEM_POOL_STATUS** type. The **usageWaterLine** field indicates the waterline.

To calculate the memory fragmentation rate, call **LOS_MemInfoGet** to obtain the remaining memory size and the maximum free memory block size in the memory pool, and then calculate the fragmentation rate of the dynamic memory pool as follows:<br>Fragmentation rate = 100 – 100 x Maximum free memory block size/Remaining memory size


#### Development Example

This example implements the following:

1. Create a monitoring task to obtain information about the memory pool.

2. Calls **LOS_MemInfoGet** to obtain the basic information about the memory pool.

3. Calculate the memory usage and fragmentation rate.


#### Sample Code

The sample code is as follows:

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **MemTest** function is called in **TestTaskEntry**.

```
#include <stdio.h>
#include <string.h>
#include "los_task.h"
#include "los_memory.h"
#include "los_config.h"

#define TEST_TASK_PRIO  5
void MemInfoTaskFunc(void)
{
    LOS_MEM_POOL_STATUS poolStatus = {0};

    /* pool is the memory address of the information to be collected. OS_SYS_MEM_ADDR is used as an example. */
    void *pool = OS_SYS_MEM_ADDR;
    LOS_MemInfoGet(pool, &poolStatus);
    /* Calculate the fragmentation rate of the memory pool. */
    float fragment = 100 - poolStatus.maxFreeNodeSize * 100.0 / poolStatus.totalFreeSize;
    /* Calculate the memory usage of the memory pool. */
    float usage = LOS_MemTotalUsedGet(pool) * 100.0 / LOS_MemPoolSizeGet(pool);
    printf("usage = %f, fragment = %f, maxFreeSize = %d, totalFreeSize = %d, waterLine = %d\n", usage, fragment, 
    		poolStatus.maxFreeNodeSize, poolStatus.totalFreeSize, poolStatus.usageWaterLine);
}

int MemTest(void)
{
    unsigned int ret;
    unsigned int taskID;
    TSK_INIT_PARAM_S taskStatus = {0};
    taskStatus.pfnTaskEntry = (TSK_ENTRY_FUNC)MemInfoTaskFunc;
    taskStatus.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    taskStatus.pcName       = "memInfo";
    taskStatus.usTaskPrio   = TEST_TASK_PRIO;
    ret = LOS_TaskCreate(&taskID, &taskStatus);
    if (ret != LOS_OK) {
        printf("task create failed\n");
        return -1;
    }
    return 0;
}
```


#### Verification

The result is as follows:


```
usage = 0.458344, fragment = 0.000000, maxFreeSize = 16474928, totalFreeSize = 16474928, waterLine = 76816

The preceding data may vary depending on the running environment.
```
## Memory Leak Check


### Basic Concepts

As an optional function of the kernel, memory leak check is used to locate dynamic memory leak problems. After this function is enabled, the dynamic memory automatically records the link registers (LRs) used when memory is allocated. If a memory leak occurs, the recorded information helps locate the memory allocated for further analysis.


### Function Configuration

**LOSCFG_MEM_LEAKCHECK** specifies the setting of the memory leak check. This function is disabled by default. To enable the function, set this macro to **1** in **target_config.h**.

**LOSCFG_MEM_RECORD_LR_CNT** specifies the number of LRs recorded. The default value is **3**. Each LR consumes the memory of **sizeof(void \*)** bytes.

**LOSCFG_MEM_OMIT_LR_CNT** specifies the number of ignored LRs. The default value is **4**, which indicates that LRs are recorded from the time when **LOS_MemAlloc** is called. You can change the value based on actual requirements. This macro is configured because:

- **LOS_MemAlloc** is also called internally.
- **LOS_MemAlloc** may be encapsulated externally.
- The number of LRs configured by **LOSCFG_MEM_RECORD_LR_CNT** is limited.

Correctly setting this macro can ignore invalid LRs and reduce memory consumption.


### Development Guidelines


#### How to Develop

Memory leak check provides a method to check for memory leak in key code logic. If this function is enabled, LR information is recorded each time when memory is allocated. When **LOS_MemUsedNodeShow** is called before and after the code snippet is checked, information about all nodes that have been used in the specified memory pool is printed. You can compare the node information. The newly added node information indicates the node where the memory leak may occur. You can locate the code based on the LR and further check whether a memory leak occurs.

The node information output by calling **LOS_MemUsedNodeShow** is in the following format: <br>Each line contains information about a node. The first column indicates the node address, based on which you can obtain complete node information using a tool such as a GNU Debugger (GDB). The second column indicates the node size, which is equal to the node header size plus the data field size. Columns 3 to 5 list the LR addresses. You can determine the specific memory location of the node based on the LR addresses and the assembly file.


```
node        size   LR[0]      LR[1]       LR[2]  
0x10017320: 0x528 0x9b004eba  0x9b004f60  0x9b005002 
0x10017848: 0xe0  0x9b02c24e  0x9b02c246  0x9b008ef0 
0x10017928: 0x50  0x9b008ed0  0x9b068902  0x9b0687c4 
0x10017978: 0x24  0x9b008ed0  0x9b068924  0x9b0687c4
0x1001799c: 0x30  0x9b02c24e  0x9b02c246  0x9b008ef0 
0x100179cc: 0x5c  0x9b02c24e  0x9b02c246  0x9b008ef0 
```

> **CAUTION**
>
> Enabling memory leak check affects memory application performance. LR addresses will be recorded for each memory node, increasing memory overhead.


#### Development Example

This example implements the following:

1. Call **LOS_MemUsedNodeShow** to print information about all nodes.

2. Simulate a memory leak by requesting memory without releasing it.

3. Call **LOS_MemUsedNodeShow** to print information about all nodes.

4. Compare the logs to obtain information about the node where a memory leak occurred.

5. Locate the code based on the LR address.


#### Sample Code

The sample code is as follows:

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **MemLeakTest** function is called in **TestTaskEntry**.

When QEMU is running, ensure that the value of **LOSCFG_MEM_FREE_BY_TASKID** in **target_config.h** is **0**.

After the memory check function is enabled, other tasks running on certain platforms may frequently print memory-related information such as "psp, start = xxxxx, end = xxxxxxx". Ignore the information or delete the print information called by **OsStackAddrGet**.


```
#include <stdio.h>
#include <string.h>
#include "los_memory.h"
#include "los_config.h"

void MemLeakTest(void)
{
    LOS_MemUsedNodeShow(LOSCFG_SYS_HEAP_ADDR);
    void *ptr1 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    void *ptr2 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    LOS_MemUsedNodeShow(LOSCFG_SYS_HEAP_ADDR);
}
```


#### Verification

The log is as follows:


```
node         size   LR[0]       LR[1]       LR[2]   
0x20001b04:  0x24   0x08001a10  0x080035ce  0x080028fc 
0x20002058:  0x40   0x08002fe8  0x08003626  0x080028fc 
0x200022ac:  0x40   0x08000e0c  0x08000e56  0x0800359e 
0x20002594:  0x120  0x08000e0c  0x08000e56  0x08000c8a 
0x20002aac:  0x56   0x08000e0c  0x08000e56  0x08004220 

node         size   LR[0]       LR[1]       LR[2]   
0x20001b04:  0x24   0x08001a10  0x080035ce  0x080028fc 
0x20002058:  0x40   0x08002fe8  0x08003626  0x080028fc 
0x200022ac:  0x40   0x08000e0c  0x08000e56  0x0800359e 
0x20002594:  0x120  0x08000e0c  0x08000e56  0x08000c8a 
0x20002aac:  0x56   0x08000e0c  0x08000e56  0x08004220 
0x20003ac4:  0x1d   0x08001458  0x080014e0  0x080041e6 
0x20003ae0:  0x1d   0x080041ee  0x08000cc2  0x00000000

The preceding data may vary depending on the running environment.
```

The difference between the two logs is as follows. The following memory nodes are suspected to have blocks with a memory leak.


```
0x20003ac4:  0x1d   0x08001458  0x080014e0  0x080041e6 
0x20003ae0:  0x1d   0x080041ee  0x08000cc2  0x00000000

The preceding data may vary depending on the running environment.
```

The following is part of the assembly file:


```
                MemLeakTest:
  0x80041d4: 0xb510         PUSH     {R4, LR}
  0x80041d6: 0x4ca8         LDR.N    R4, [PC, #0x2a0]       ; g_memStart
  0x80041d8: 0x0020         MOVS     R0, R4
  0x80041da: 0xf7fd 0xf93e  BL       LOS_MemUsedNodeShow    ; 0x800145a
  0x80041de: 0x2108         MOVS     R1, #8
  0x80041e0: 0x0020         MOVS     R0, R4
  0x80041e2: 0xf7fd 0xfbd9  BL       LOS_MemAlloc           ; 0x8001998
  0x80041e6: 0x2108         MOVS     R1, #8
  0x80041e8: 0x0020         MOVS     R0, R4
  0x80041ea: 0xf7fd 0xfbd5  BL       LOS_MemAlloc           ; 0x8001998
  0x80041ee: 0x0020         MOVS     R0, R4
  0x80041f0: 0xf7fd 0xf933  BL       LOS_MemUsedNodeShow    ; 0x800145a
  0x80041f4: 0xbd10         POP      {R4, PC}
  0x80041f6: 0x0000         MOVS     R0, R0
  
  The preceding data may vary depending on the running environment.
```

The memory node addressed by **0x080041ee** is not released after being requested in **MemLeakTest**.

## Memory Corruption Check


### Basic Concepts

As an optional function of the kernel, memory corruption check is used to check the integrity of a dynamic memory pool. This mechanism can detect memory corruption errors in the memory pool in a timely manner and provide alerts. It helps reduce problem locating costs and increase troubleshooting efficiency.


### Function Configuration

**LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK** specifies the setting of the memory corruption check. This function is disabled by default. To enable the function, set this macro to **1** in **target_config.h**.

1. If this macro is enabled, the memory pool integrity will be checked in real time upon each memory allocation.

2. If this macro is not enabled, you can call **LOS_MemIntegrityCheck** to check the memory pool integrity when required. Using **LOS_MemIntegrityCheck** does not affect the system performance. However, the check accuracy decreases because the node header does not contain the magic number (which is available only when **LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK** is enabled).

This check only detects the corrupted memory node and provides information about the previous node (because memory is contiguous, a node is most likely corrupted by the previous node). To further determine the location where the previous node is requested, you need to enable the memory leak check and use LRs to locate the fault.

> **CAUTION**
>
> If memory corruption check is enabled, a magic number is added to the node header, which increases the size of the node header.  The real-time integrity check has a great impact on the performance. In performance-sensitive scenarios, you are advised to disable this function and use **LOS_MemIntegrityCheck** to check the memory pool integrity.


### Development Guidelines


#### How to Develop

Check for memory corruption by calling **LOS_MemIntegrityCheck**. If no memory corruption occurs, **0** is returned and no log is output. If memory corruption occurs, the related log is output. For details, see the output of the following example.


#### Development Example

This example implements the following:

1. Request two physically adjacent memory blocks.

2. Use **memset** to construct an out-of-bounds access and overwrites the first four bytes of the next node.

3. Call **LOS_MemIntegrityCheck** to check whether memory corruption occurs.


#### Sample Code

The sample code is as follows:

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **MemIntegrityTest** function is called in **TestTaskEntry**.

When QEMU is running, ensure that the value of **LOSCFG_MEM_FREE_BY_TASKID** in **target_config.h** is **0**.

Because the exception is triggered intentionally, you need to restart QEMU when the execution is complete. For example, open a new terminal and run **killall qemu-system-arm**.


```
#include <stdio.h>
#include <string.h>
#include "los_memory.h"
#include "los_config.h"

void MemIntegrityTest(void)
{
    /* Request two physically adjacent memory blocks. */
    void *ptr1 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    void *ptr2 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    /* Construct an out-of-bounds access to cause memory corruption. The memory block of the first node is 8 bytes. Clearing 12 bytes overwrites the header of the second memory node. */
    memset(ptr1, 0, 8 + 4);
    LOS_MemIntegrityCheck(LOSCFG_SYS_HEAP_ADDR);
}
```


#### Verification

The log is as follows:


```

/* Error information indicating the field corrupted. In this example, the first four bytes of the next node are cleared, that is, the magic number field is corrupted. */
[ERR][IT_TST_INI][OsMemMagicCheckPrint], 1664, memory check error!
memory used but magic num wrong, magic num = 0x0

 /* Key information about the corrupted node and its previous node, including the address of the previous node, magic number of the node, and sizeAndFlag of the node. In this example, the magic number of the corrupted node is cleared. */
 broken node head: 0x2103d7e8  0x0  0x80000020, prev node head: 0x2103c7cc  0xabcddcba  0x80000020

 /*The node LR information can be output only after the memory leak check is enabled. */
 broken node head LR info:
 LR[0]:0x2101906c
 LR[1]:0x0
 LR[2]:0x0

 /* Based on the LR information, you can determine where the previous node in requsted in the assembly file and check the use of the node. */
 pre node head LR info:
 LR[0]:0x2101906c
 LR[1]:0x0
 LR[2]:0x0
 
 /* Addresses of the corrupted node and its previous node. */
[ERR][IT_TST_INI]Memory integrity check error, cur node: 0x2103d784, pre node: 0x0

 The preceding data may vary depending on the running environment.
```
