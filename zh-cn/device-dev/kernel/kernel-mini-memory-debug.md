# 内存调测


内存调测方法旨在辅助定位动态内存相关问题，提供了基础的动态内存池信息统计手段，向用户呈现内存池水线、碎片率等信息；提供了内存泄漏检测手段，方便用户准确定位存在内存泄漏的代码行，也可以辅助分析系统各个模块内存的使用情况；提供了踩内存检测手段，可以辅助定位越界踩内存的场景。


## 内存信息统计


### 基础概念

内存信息包括内存池大小、内存使用量、剩余内存大小、最大空闲内存、内存水线、内存节点数统计、碎片率等。

- 内存水线：即内存池的最大使用量，每次申请和释放时，都会更新水线值，实际业务可根据该值，优化内存池大小；

- 碎片率：衡量内存池的碎片化程度，碎片率高表现为内存池剩余内存很多，但是最大空闲内存块很小，可以用公式（fragment=100-100\*最大空闲内存块大小/剩余内存大小）来度量；

- 其他参数：通过调用接口（详见[内存管理](../kernel/kernel-mini-basic-memory.md)章节接口说明），扫描内存池的节点信息，统计出相关信息。


### 功能配置

LOSCFG_MEM_WATERLINE：开关宏，默认打开；若关闭这个功能，在target_config.h中将这个宏定义为0。如需获取内存水线，需要打开该配置。


### 开发指导


#### 开发流程

关键结构体介绍：


```
typedef struct {
    UINT32 totalUsedSize;       // 内存池的内存使用量
    UINT32 totalFreeSize;       // 内存池的剩余内存大小
    UINT32 maxFreeNodeSize;     // 内存池的最大空闲内存块大小
    UINT32 usedNodeNum;         // 内存池的非空闲内存块个数
    UINT32 freeNodeNum;         // 内存池的空闲内存块个数
#if (LOSCFG_MEM_WATERLINE == 1) // 默认打开，如需关闭，在target_config.h中将该宏设置为0
    UINT32 usageWaterLine;      // 内存池的水线值
#endif
} LOS_MEM_POOL_STATUS;
```

- 内存水线获取：调用LOS_MemInfoGet接口，第1个参数是内存池首地址，第2个参数是LOS_MEM_POOL_STATUS类型的句柄，其中字段usageWaterLine即水线值。

- 内存碎片率计算：同样调用LOS_MemInfoGet接口，可以获取内存池的剩余内存大小和最大空闲内存块大小，然后根据公式（fragment=100-100\*最大空闲内存块大小/剩余内存大小）得出此时的动态内存池碎片率。


#### 编程实例

本实例实现如下功能：

1.创建一个监控任务，用于获取内存池的信息；

2.调用LOS_MemInfoGet接口，获取内存池的基础信息；

3.利用公式算出使用率及碎片率。


#### 示例代码

代码实现如下：

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数MemTest。

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

    /* pool为要统计信息的内存地址，此处以OS_SYS_MEM_ADDR为例 */
    void *pool = OS_SYS_MEM_ADDR;
    LOS_MemInfoGet(pool, &poolStatus);
    /* 算出内存池当前的碎片率百分比 */
    float fragment = 100 - poolStatus.maxFreeNodeSize * 100.0 / poolStatus.totalFreeSize;
    /* 算出内存池当前的使用率百分比 */
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


#### 结果验证

编译运行输出的结果如下：


```
usage = 0.458344, fragment = 0.000000, maxFreeSize = 16474928, totalFreeSize = 16474928, waterLine = 76816

根据实际运行环境，上文中的数据会有差异，非固定结果
```
## 内存泄漏检测


### 基础概念

内存泄漏检测机制作为内核的可选功能，用于辅助定位动态内存泄漏问题。开启该功能，动态内存机制会自动记录申请内存时的函数调用关系（下文简称LR）。如果出现泄漏，就可以利用这些记录的信息，找到内存申请的地方，方便进一步确认。


### 功能配置

1. LOSCFG_MEM_LEAKCHECK：开关宏，默认关闭；若打开这个功能，在target_config.h中将这个宏定义为1。

2. LOSCFG_MEM_RECORD_LR_CNT：记录的LR层数，默认3层；每层LR消耗sizeof(void \*)字节数的内存。

3. LOSCFG_MEM_OMIT_LR_CNT：忽略的LR层数，默认4层，即从调用LOS_MemAlloc的函数开始记录，可根据实际情况调整。为啥需要这个配置？有3点原因如下：
   - LOS_MemAlloc接口内部也有函数调用；
   - 外部可能对LOS_MemAlloc接口有封装；
   - LOSCFG_MEM_RECORD_LR_CNT 配置的LR层数有限；

正确配置这个宏，将无效的LR层数忽略，就可以记录有效的LR层数，节省内存消耗。


### 开发指导


#### 开发流程

该调测功能可以分析关键的代码逻辑中是否存在内存泄漏。开启这个功能，每次申请内存时，会记录LR信息。在需要检测的代码段前后，调用LOS_MemUsedNodeShow接口，每次都会打印指定内存池已使用的全部节点信息，对比前后两次的节点信息，新增的节点信息就是疑似泄漏的内存节点。通过LR，可以找到具体申请的代码位置，进一步确认是否泄漏。

调用LOS_MemUsedNodeShow接口输出的节点信息格式如下：每1行为一个节点信息；第1列为节点地址，可以根据这个地址，使用GDB等手段查看节点完整信息；第2列为节点的大小，等于节点头大小+数据域大小；第3~5列为函数调用关系LR地址，可以根据这个值，结合汇编文件，查看该节点具体申请的位置。


```
node        size   LR[0]      LR[1]       LR[2]  
0x10017320: 0x528 0x9b004eba  0x9b004f60  0x9b005002 
0x10017848: 0xe0  0x9b02c24e  0x9b02c246  0x9b008ef0 
0x10017928: 0x50  0x9b008ed0  0x9b068902  0x9b0687c4 
0x10017978: 0x24  0x9b008ed0  0x9b068924  0x9b0687c4
0x1001799c: 0x30  0x9b02c24e  0x9b02c246  0x9b008ef0 
0x100179cc: 0x5c  0x9b02c24e  0x9b02c246  0x9b008ef0 
```

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> 开启内存检测会影响内存申请的性能，且每个内存节点都会记录LR地址，内存开销也加大。


#### 编程实例

本实例实现如下功能：构建内存泄漏代码段。

1. 调用LOS_MemUsedNodeShow接口，输出全部节点信息打印；

2. 申请内存，但没有释放，模拟内存泄漏；

3. 再次调用LOS_MemUsedNodeShow接口，输出全部节点信息打印；

4. 将两次log进行对比，得出泄漏的节点信息；

5. 通过LR地址，找出泄漏的代码位置；


#### 示例代码

代码实现如下：

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数MemLeakTest。

qemu平台运行时需确保target_config.h 中对应的LOSCFG_MEM_FREE_BY_TASKID为0。

由于打开内存检测后，部分平台有其他任务运行，会频繁调用内存相关打印如：psp, start = xxxxx, end = xxxxxxx，请忽略打印或删除OsStackAddrGet函数中调用的打印即可。


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


#### 结果验证

编译运行输出示例log如下：


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

根据实际运行环境，上文中的数据会有差异，非固定结果
```

对比两次log，差异如下，这些内存节点就是疑似泄漏的内存块：


```
0x20003ac4:  0x1d   0x08001458  0x080014e0  0x080041e6 
0x20003ae0:  0x1d   0x080041ee  0x08000cc2  0x00000000

根据实际运行环境，上文中的数据会有差异，非固定结果
```

部分汇编文件如下:


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
  
  根据实际运行环境，上文中的数据会有差异，非固定结果
```

其中，通过查找0x080041ee，就可以发现该内存节点是在MemLeakTest接口里申请的且是没有释放的。

## 踩内存检测


### 基础概念

踩内存检测机制作为内核的可选功能，用于检测动态内存池的完整性。通过该机制，可以及时发现内存池是否发生了踩内存问题，并给出错误信息，便于及时发现系统问题，提高问题解决效率，降低问题定位成本。


### 功能配置

LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK：开关宏，默认关闭；若打开这个功能，在target_config.h中将这个宏定义为1。

1. 开启这个功能，每次申请内存，会实时检测内存池的完整性。

2. 如果不开启该功能，也可以调用LOS_MemIntegrityCheck接口检测，但是每次申请内存时，不会实时检测内存完整性，而且由于节点头没有魔鬼数字（开启时才有，省内存），检测的准确性也会相应降低，但对于系统的性能没有影响，故根据实际情况开关该功能。

由于该功能只会检测出哪个内存节点被破坏了，并给出前节点信息（因为内存分布是连续的，当前节点最有可能被前节点破坏）。如果要进一步确认前节点在哪里申请的，需开启内存泄漏检测功能，通过LR记录，辅助定位。

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> 开启该功能，节点头多了魔鬼数字字段，会增大节点头大小。由于实时检测完整性，故性能影响较大；若性能敏感的场景，可以不开启该功能，使用LOS_MemIntegrityCheck接口检测。


### 开发指导


#### 开发流程

通过调用LOS_MemIntegrityCheck接口检测内存池是否发生了踩内存，如果没有踩内存问题，那么接口返回0且没有log输出；如果存在踩内存问题，那么会输出相关log，详见下文编程实例的结果输出。


#### 编程实例

本实例实现如下功能：

1. 申请两个物理上连续的内存块；

2. 通过memset构造越界访问，踩到下个节点的头4个字节；

3. 调用LOS_MemIntegrityCheck检测是否发生踩内存。


#### 示例代码

代码实现如下：

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数MemIntegrityTest。

qemu平台运行时需确保target_config.h 中对应的LOSCFG_MEM_FREE_BY_TASKID为0。

由于执行时主动触发异常，执行结束后需要重启qemu（例如打开一个新的终端界面输入killall qemu-system-arm）


```
#include <stdio.h>
#include <string.h>
#include "los_memory.h"
#include "los_config.h"

void MemIntegrityTest(void)
{
    /* 申请两个物理连续的内存块 */
    void *ptr1 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    void *ptr2 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    /* 第一个节点内存块大小是8字节，那么12字节的清零，会踩到第二个内存节点的节点头，构造踩内存场景 */
    memset(ptr1, 0, 8 + 4);
    LOS_MemIntegrityCheck(LOSCFG_SYS_HEAP_ADDR);
}
```


#### 结果验证

编译运行输出log如下：


```

/* 提示信息，检测到哪个字段被破坏了，用例构造了将下个节点的头4个字节清零，即魔鬼数字字段 */
[ERR][IT_TST_INI][OsMemMagicCheckPrint], 1664, memory check error!
memory used but magic num wrong, magic num = 0x0

 /* 被破坏节点和其前节点关键字段信息，分别为其前节点地址、节点的魔鬼数字、节点的sizeAndFlag；可以看出被破坏节点的魔鬼数字字段被清零，符合用例场景 */
 broken node head: 0x2103d7e8  0x0  0x80000020, prev node head: 0x2103c7cc  0xabcddcba  0x80000020

 /* 节点的LR信息需要开启前文的内存泄漏检测功能才有有效输出 */
 broken node head LR info:
 LR[0]:0x2101906c
 LR[1]:0x0
 LR[2]:0x0

 /* 通过LR信息，可以在汇编文件中查找前节点是哪里申请，然后排查其使用的准确性 */
 pre node head LR info:
 LR[0]:0x2101906c
 LR[1]:0x0
 LR[2]:0x0
 
 /* 被破坏节点和其前节点的地址 */
[ERR][IT_TST_INI]Memory integrity check error, cur node: 0x2103d784, pre node: 0x0

 根据实际运行环境，上文中的数据会有差异，非固定结果
```
