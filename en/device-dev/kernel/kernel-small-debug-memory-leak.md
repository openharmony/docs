# Memory Leak Check


## Basic Concepts

As an optional function of the kernel, memory leak check is used to locate dynamic memory leak problems. After this function is enabled, the dynamic memory mechanism automatically records the link registers (LRs) used when memory is allocated. If a memory leak occurs, the recorded information helps locate the memory allocated for further analysis.


## Function Configuration

**LOSCFG_MEM_LEAKCHECK** specifies the setting of the memory leak check. This function is disabled by default. You can enable it in **Debug-&gt; Enable MEM Debug-&gt; Enable Function call stack of Mem operation recorded**.

**LOS_RECORD_LR_CNT** specifies the number of LRs recorded. The default value is **3**. Each LR consumes the memory of **sizeof(void *)** bytes.

**LOS_OMIT_LR_CNT** specifies the number of ignored LRs. The default value is **2**, which indicates that LRs are recorded from the time when **LOS_MemAlloc** is called. You can change the value based on actual requirements. The reasons for this configuration are as follows:

- **LOS_MemAlloc** is also called internally.
- **LOS_MemAlloc** may be encapsulated externally.
- The number of LRs configured by **LOS_RECORD_LR_CNT** is limited.

Correctly setting this macro can ignore invalid LRs and reduce memory consumption.


## Development Guidelines


### How to Develop

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
> Enabling memory leak check affects memory application performance. LR addresses will be recorded for each memory node, increasing memory overhead.


### Development Example

This example implements the following:

1. Call **OsMemUsedNodeShow** to print information about all nodes.

2. Simulate a memory leak by requesting memory without releasing it.

3. Call **OsMemUsedNodeShow** to print information about all nodes.

4. Compare the logs to obtain information about the node where a memory leak occurred.

5. Locate the code based on the LR address.


**Sample Code**

You can compile and verify the sample code in **kernel/liteos_a/testsuites/kernel/src/osTest.c**. The **MemLeakTest()** function is called in **TestTaskEntry**.

In this example, a memory pool is created. To achieve this purpose, you need to define **LOSCFG_MEM_MUL_POOL** in **target_config.h**.

The sample code is as follows:

```c
#include <stdio.h>
#include <string.h>
#include "los_memory.h"
#include "los_config.h"

#define TEST_NEW_POOL_SIZE 2000
#define TEST_MALLOC_SIZE 8

void MemLeakTest(void)
{
    VOID *pool = NULL;

    /* Create a memory pool. */
    pool = LOS_MemAlloc(OS_SYS_MEM_ADDR, TEST_NEW_POOL_SIZE);
    (VOID)LOS_MemInit(pool, TEST_NEW_POOL_SIZE);

    OsMemUsedNodeShow(pool);
    void *ptr1 = LOS_MemAlloc(pool, TEST_MALLOC_SIZE);
    void *ptr2 = LOS_MemAlloc(pool, TEST_MALLOC_SIZE);
    OsMemUsedNodeShow(pool);
    
    /* Release the memory pool. */
    (VOID)LOS_MemDeInit(pool);
}
```


**Verification**


The log is as follows:

```
/* Log for the first OsMemUsedNodeShow. Because the memory pool is not allocated, there is no memory node. */
node            LR[0]       LR[1]       LR[2]


/* Log for the second OsMemUsedNodeShow. There are two memory nodes. */
node            LR[0]       LR[1]       LR[2]
0x00402e0d90:  0x004009f040  0x0040037614  0x0040005480
0x00402e0db0:  0x004009f04c  0x0040037614  0x0040005480

```


The difference between the two logs is as follows. The following memory nodes are suspected to have blocks with a memory leak.

```
0x00402e0d90:  0x004009f040  0x0040037614  0x0040005480
0x00402e0db0:  0x004009f04c  0x0040037614  0x0040005480
```


The following is part of the assembly file:

```
4009f014: 7d 1e a0 e3  	mov	r1, #2000
4009f018: 00 00 90 e5  	ldr	r0, [r0]
4009f01c: 67 7a fe eb  	bl	#-398948 <LOS_MemAlloc>
4009f020: 7d 1e a0 e3  	mov	r1, #2000
4009f024: 00 40 a0 e1  	mov	r4, r0
4009f028: c7 79 fe eb  	bl	#-399588 <LOS_MemInit>
4009f02c: 04 00 a0 e1  	mov	r0, r4
4009f030: 43 78 fe eb  	bl	#-401140 <OsMemUsedNodeShow>
4009f034: 04 00 a0 e1  	mov	r0, r4
4009f038: 08 10 a0 e3  	mov	r1, #8
4009f03c: 5f 7a fe eb  	bl	#-398980 <LOS_MemAlloc>
4009f040: 04 00 a0 e1  	mov	r0, r4
4009f044: 08 10 a0 e3  	mov	r1, #8
4009f048: 5c 7a fe eb  	bl	#-398992 <LOS_MemAlloc>
4009f04c: 04 00 a0 e1  	mov	r0, r4
4009f050: 3b 78 fe eb  	bl	#-401172 <OsMemUsedNodeShow>
4009f054: 3c 00 9f e5  	ldr	r0, [pc, #60]
4009f058: 40 b8 fe eb  	bl	#-335616 <dprintf>
4009f05c: 04 00 a0 e1  	mov	r0, r4
4009f060: 2c 7a fe eb  	bl	#-399184 <LOS_MemDeInit>
```


The memory node addressed by **0x4009f040** is not released after being allocated in **MemLeakTest**.
