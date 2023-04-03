# 内存信息统计


## 基础概念

内存信息包括内存池大小、内存使用量、剩余内存大小、最大空闲内存、内存水线、内存节点数统计、碎片率等。

- 内存水线：即内存池的最大使用量，每次申请和释放时，都会更新水线值，实际业务可根据该值，优化内存池大小；

- 碎片率：衡量内存池的碎片化程度，碎片率高表现为内存池剩余内存很多，但是最大空闲内存块很小，可以用公式（fragment=100-100\*最大空闲内存块大小/剩余内存大小）来度量；

- 其他统计信息：调用接口LOS_MemInfoGet时，会扫描内存池的节点信息，统计出相关信息。


## 功能配置

LOSCFG_MEM_WATERLINE：开关宏，默认关闭；若需要打开这个功能，可以在配置项中开启“Debug-&gt; Enable MEM Debug-&gt; Enable memory pool waterline or not”。如需获取内存水线，需要打开该配置。


## 开发指导


### 开发流程

关键结构体介绍：


```c
typedef struct {
    UINT32 totalUsedSize;       // 内存池的内存使用量
    UINT32 totalFreeSize;       // 内存池的剩余内存大小
    UINT32 maxFreeNodeSize;     // 内存池的最大空闲内存块大小
    UINT32 usedNodeNum;         // 内存池的非空闲内存块个数
    UINT32 freeNodeNum;         // 内存池的空闲内存块个数
#if (LOSCFG_MEM_WATERLINE == 1)     // 默认关闭，可以通过menuconfig配置工具打开
    UINT32 usageWaterLine;      // 内存池的水线值
#endif
} LOS_MEM_POOL_STATUS;
```

- 内存水线获取：调用 LOS_MemInfoGet(VOID *pool,  LOS_MEM_POOL_STATUS *poolStatus)接口，第1个参数是内存池首地址，第2个参数是LOS_MEM_POOL_STATUS类型的句柄，其中字段usageWaterLine即水线值。

- 内存碎片率计算：同样调用LOS_MemInfoGet接口，可以获取内存池的剩余内存大小和最大空闲内存块大小，然后根据公式（fragment=100-100\*最大空闲内存块大小/剩余内存大小）得出此时的动态内存池碎片率。


### 编程实例

本实例实现如下功能：

1. 创建一个监控任务，用于获取内存池的信息；

2. 调用LOS_MemInfoGet接口，获取内存池的基础信息；

3. 利用公式算出使用率及碎片率。

**示例代码**

本演示代码在 . kernel /liteos_a/testsuites /kernel /src /osTest.c中编译验证，在TestTaskEntry中调用验证入口函数MemTest。

代码实现如下：

```c
#include <stdio.h>
#include <string.h>
#include "los_task.h"
#include "los_memory.h"
#include "los_config.h"

void MemInfoTaskFunc(void)
{
    LOS_MEM_POOL_STATUS poolStatus = {0};

    /* pool为要统计信息的内存地址，此处以OS_SYS_MEM_ADDR为例 */
    void *pool = OS_SYS_MEM_ADDR;
    LOS_MemInfoGet(pool, &poolStatus);
    /* 算出内存池当前的碎片率百分比 */
    unsigned char fragment = 100 - poolStatus.maxFreeNodeSize * 100 / poolStatus.totalFreeSize;
    /* 算出内存池当前的使用率百分比 */
    unsigned char usage = LOS_MemTotalUsedGet(pool) * 100 / LOS_MemPoolSizeGet(pool);
    dprintf("usage = %d, fragment = %d, maxFreeSize = %d, totalFreeSize = %d, waterLine = %d\n", usage, fragment,                            poolStatus.maxFreeNodeSize, poolStatus.totalFreeSize, poolStatus.usageWaterLine);
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
        dprintf("task create failed\n");
        return LOS_NOK;
    }
    return LOS_OK;
}
```


**结果验证**


编译运行输出的结果如下：

根据实际运行环境，数据会有差异

```
usage = 22, fragment = 3, maxFreeSize = 49056, totalFreeSize = 50132, waterLine = 1414
```
