# Memory Information Statistics

## Basic Concepts

Memory information includes the memory pool size, memory usage, remaining memory size, maximum free memory, memory waterline, number of memory nodes, and fragmentation rate.

-   Memory waterline: indicates the maximum memory used in a memory pool. The waterline value is updated upon each memory allocation and release. The memory pool size can be optimized based on this value.

-   Fragmentation rate: indicates the fragmentation degree of the memory pool. If the fragmentation rate is high, there are a large number of free memory blocks in the memory pool but each block is small. You can use the following formula to calculate the fragmentation rate:

    Fragmentation rate = 100 – 100 x Maximum free memory block size/Remaining memory size


-   Other parameters: You can call APIs \(described in  [Memory Management](kernel-mini-basic-memory-basic.md)\) to scan node information in the memory pool and collect statistics.

## Function Configuration

**LOSCFG\_MEM\_WATERLINE**: specifies the setting of the memory information statistics function. This function is enabled by default. To disable the function, set this macro to  **0**  in  **target\_config.h**. If you want to obtain the memory waterline, you must enable this macro.

## Development Guidelines

### How to Develop

Key structure:

```
typedef struct {
    UINT32 totalUsedSize; // Memory usage of the memory pool
    UINT32 totalFreeSize; // Remaining memory in the memory pool
    UINT32 maxFreeNodeSize; // Maximum size of the free memory block in the memory pool
    UINT32 usedNodeNum; // Number of non-free memory blocks in the memory pool
    UINT32 freeNodeNum; // Number of free memory blocks in the memory pool
#if (LOSCFG_MEM_WATERLINE == 1) // This macro is enabled by default. To disable it, set it to 0 in target_config.h.
    UINT32 usageWaterLine; // Waterline of the memory pool
#endif
} LOS_MEM_POOL_STATUS;
```

-   To obtain the memory waterline, call  **LOS\_MemInfoGet**. The first parameter in the API is the start address of the memory pool, and the second parameter is the handle of the  **LOS\_MEM\_POOL\_STATUS**  type. The  **usageWaterLine**  field indicates the waterline.

-   To calculate the memory fragmentation rate, call  **LOS\_MemInfoGet**  to obtain the remaining memory size and the maximum free memory block size in the memory pool, and then calculate the fragmentation rate of the dynamic memory pool as follows:

    Fragmentation rate = 100 – 100 x Maximum free memory block size/Remaining memory size


### Development Example

This example implements the following:

1. Create a monitoring task to obtain information about the memory pool.

2. Call  **LOS\_MemInfoGet**  to obtain the basic information about the memory pool.

3. Calculate the memory usage and fragmentation rate.

### Sample Code

The sample code is as follows:

```
#include <stdio.h>
#include <string.h>
#include "los_task.h"
#include "los_memory.h"
#include "los_config.h"


void MemInfoTaskFunc(void)
{
    LOS_MEM_POOL_STATUS poolStatus = {0};

    /* pool is the memory address of the information to be collected. OS_SYS_MEM_ADDR is used as an example.*/
    void *pool = OS_SYS_MEM_ADDR;
    LOS_MemInfoGet(pool, &poolStatus);
    /* Calculate the fragmentation rate of the memory pool. */
    unsigned char fragment = 100 - poolStatus.maxFreeNodeSize * 100 / poolStatus.totalFreeSize;
    /* Calculate the memory usage of the memory pool. */
    unsigned char usage = LOS_MemTotalUsedGet(pool) * 100 / LOS_MemPoolSizeGet(pool);
    printf("usage = %d, fragment = %d, maxFreeSize = %d, totalFreeSize = %d, waterLine = %d\n", usage, fragment, poolStatus.maxFreeNodeSize, 
           poolStatus.totalFreeSize, poolStatus.usageWaterLine);
}

int MemTest(void)
{
    unsigned int ret;
    unsigned int taskID;
    TSK_INIT_PARAM_S taskStatus = {0};
    taskStatus.pfnTaskEntry = (TSK_ENTRY_FUNC)MemInfoTaskFunc;
    taskStatus.uwStackSize  = 0x1000;
    taskStatus.pcName       = "memInfo";
    taskStatus.usTaskPrio   = 10;
    ret = LOS_TaskCreate(&taskID, &taskStatus);
    if (ret != LOS_OK) {
        printf("task create failed\n");
        return -1;
    }
    return 0;
}
```

### Verification

The result is as follows:

```
usage = 22, fragment = 3, maxFreeSize = 49056, totalFreeSize = 50132, waterLine = 1414
```

