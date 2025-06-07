# 内存管理
## 基本概念


内存管理模块管理系统的内存资源，它是操作系统的核心模块之一，主要包括内存的初始化、分配以及释放。


在系统运行过程中，内存管理模块通过对内存的申请/释放来管理用户和OS对内存的使用，使内存的利用率和使用效率达到最优，同时最大限度地解决系统的内存碎片问题。


OpenHarmony LiteOS-M的内存管理分为静态内存管理和动态内存管理，提供内存初始化、分配、释放等功能。


- 动态内存：在动态内存池中分配用户指定大小的内存块。
  - 优点：按需分配。
  - 缺点：内存池中可能出现碎片。

- 静态内存：在静态内存池中分配用户初始化时预设（固定）大小的内存块。
  - 优点：分配和释放效率高，静态内存池中无碎片。
  - 缺点：只能申请到初始化预设大小的内存块，不能按需申请。
## 静态内存


### 运行机制

静态内存实质上是一个静态数组，静态内存池内的块大小在初始化时设定，初始化后块大小不可变更。

静态内存池由一个控制块LOS_MEMBOX_INFO和若干相同大小的内存块LOS_MEMBOX_NODE构成。控制块位于内存池头部，用于内存块管理，包含内存块大小uwBlkSize，内存块数量uwBlkNum，已分配使用的内存块数量uwBlkCnt和空闲内存块链表stFreeList。内存块的申请和释放以块大小为粒度，每个内存块包含指向下一个内存块的指针pstNext。

  **图1** 静态内存示意图

  ![zh-cn_image_0000001199352039](figures/zh-cn_image_0000001199352039.png)


### 开发指导


#### 使用场景

当用户需要使用固定长度的内存时，可以通过静态内存分配的方式获取内存，一旦使用完毕，通过静态内存释放函数归还所占用内存，使之可以重复使用。


#### 接口说明

OpenHarmony LiteOS-M的静态内存管理主要为用户提供以下功能，接口详细信息可以查看API参考。

  **表1** 静态内存模块接口

| 功能分类 | 接口名 |
| -------- | -------- |
| 初始化静态内存池 | LOS_MemboxInit：初始化一个静态内存池，根据入参设定其起始地址、总大小及每个内存块大小。 |
| 清除静态内存块内容 | LOS_MemboxClr：清零从静态内存池中申请的静态内存块的内容。 |
| 申请、释放静态内存 | &nbsp;LOS_MemboxAlloc：从指定的静态内存池中申请一块静态内存块。<br/>&nbsp;LOS_MemboxFree：释放从静态内存池中申请的一块静态内存块。 |
| 获取、打印静态内存池信息 | &nbsp;LOS_MemboxStatisticsGet：获取指定静态内存池的信息，包括内存池中总内存块数量、已经分配出去的内存块数量、每个内存块的大小。<br/>&nbsp;LOS_ShowBox：打印指定静态内存池所有节点信息，打印等级是LOG_INFO_LEVEL（当前打印等级配置是PRINT_LEVEL），包括内存池起始地址、内存块大小、总内存块数量、每个空闲内存块的起始地址、所有内存块的起始地址。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 初始化后的内存池的内存块数量，不等于总大小除于内存块大小，因为内存池的控制块和每个内存块的控制头，都存在内存开销，设置总大小时，需要将这些因素考虑进去。


#### 开发流程

本节介绍使用静态内存的典型场景开发流程。

1. 规划一片内存区域作为静态内存池。

2. 调用LOS_MemboxInit初始化静态内存池。
   初始化会将入参指定的内存区域分割为N块（N值取决于静态内存总大小和块大小），将所有内存块挂到空闲链表，在内存起始处放置控制头。

3. 调用LOS_MemboxAlloc接口分配静态内存。
   系统将会从空闲链表中获取第一个空闲块，并返回该内存块的起始地址。

4. 调用LOS_MemboxClr接口。
   将入参地址对应的内存块清零。

5. 调用LOS_MemboxFree接口。
   将该内存块加入空闲链表。


#### 编程实例

本实例执行以下步骤：

1. 初始化一个静态内存池。

2. 从静态内存池中申请一块静态内存。

3. 在内存块存放一个数据。

4. 打印出内存块中的数据。

5. 清除内存块中的数据。

6. 释放该内存块。
   示例代码如下：
   
   本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数ExampleStaticMem。


```
#include "los_membox.h"

#define MEMBOX_POOL_SIZE    100
#define MEMBOX_BLOCK_SZIE   10
#define MEMBOX_WR_TEST_NUM  828
VOID ExampleStaticMem(VOID)
{
    UINT32 *mem = NULL;
    UINT32 blkSize = MEMBOX_BLOCK_SZIE;
    UINT32 poolSize = MEMBOX_POOL_SIZE;
    UINT32 boxMem[MEMBOX_POOL_SIZE];
    UINT32 ret;

    /* 内存池初始化 */
    ret = LOS_MemboxInit(&boxMem[0], poolSize, blkSize);
    if(ret != LOS_OK) {
        printf("Membox init failed!\n");
        return;
    } else {
        printf("Membox init success!\n");
    }

    /* 申请内存块 */
    mem = (UINT32 *)LOS_MemboxAlloc(boxMem);
    if (mem == NULL) {
        printf("Mem alloc failed!\n");
        return;
    }
    printf("Mem alloc success!\n");

    /* 内存地址读写验证 */
    *mem = MEMBOX_WR_TEST_NUM;
    printf("*mem = %d\n", *mem);

    /* 清除内存内容 */
    LOS_MemboxClr(boxMem, mem);
    printf("Mem clear success \n*mem = %d\n", *mem);

    /* 释放内存 */
    ret = LOS_MemboxFree(boxMem, mem);
    if (LOS_OK == ret) {
        printf("Mem free success!\n");
    } else {
        printf("Mem free failed!\n");
    }

    return;
}

```


#### 结果验证

输出结果如下：


```
Membox init success!
Mem alloc success!
*mem = 828
Mem clear success   
*mem = 0
Mem free success!
```
## 动态内存


### 运行机制

动态内存管理，即在内存资源充足的情况下，根据用户需求，从系统配置的一块比较大的连续内存（内存池，也是堆内存）中分配任意大小的内存块。当用户不需要该内存块时，又可以释放回系统供下一次使用。与静态内存相比，动态内存管理的优点是按需分配，缺点是内存池中容易出现碎片。

OpenHarmony LiteOS-M动态内存在TLSF算法的基础上，对区间的划分进行了优化，获得更优的性能，降低了碎片率。动态内存核心算法框图如下：

  **图2** 轻量系统动态内存核心算法

  ![zh-cn_image_0000001199352445](figures/zh-cn_image_0000001199352445.png)

根据空闲内存块的大小，使用多个空闲链表来管理。根据内存空闲块大小分为两个部分：[4, 127]和[2<sup>7</sup>, 2<sup>31</sup>]，如上图size class所示：

1. 对[4,127]区间的内存进行等分，如上图下半部分所示，分为31个小区间，每个小区间对应内存块大小为4字节的倍数。每个小区间对应一个空闲内存链表和用于标记对应空闲内存链表是否为空的一个比特位，值为1时，空闲链表非空。[4,127]区间的31个小区间内存对应31个比特位进行标记链表是否为空。

2. 大于127字节的空闲内存块，按照2的次幂区间大小进行空闲链表管理。总共分为24个小区间，每个小区间又等分为8个二级小区间，见上图上半部分的Size Class和Size SubClass部分。每个二级小区间对应一个空闲链表和用于标记对应空闲内存链表是否为空的一个比特位。总共24\*8=192个二级小区间，对应192个空闲链表和192个比特位进行标记链表是否为空。

例如，当有40字节的空闲内存需要插入空闲链表时，对应小区间[40,43]，第10个空闲链表，位图标记的第10比特位。把40字节的空闲内存挂载第10个空闲链表上，并判断是否需要更新位图标记。当需要申请40字节的内存时，根据位图标记获取存在满足申请大小的内存块的空闲链表，从空闲链表上获取空闲内存节点。如果分配的节点大于需要申请的内存大小，进行分割节点操作，剩余的节点重新挂载到相应的空闲链表上。当有580字节的空闲内存需要插入空闲链表时，对应二级小区间[2^9,2^9+2^6]，第31+2\*8=47个空闲链表，并使用位图的第47个比特位来标记链表是否为空。把580字节的空闲内存挂载第47个空闲链表上，并判断是否需要更新位图标记。当需要申请580字节的内存时，根据位图标记获取存在满足申请大小的内存块的空闲链表，从空闲链表上获取空闲内存节点。如果分配的节点大于需要申请的内存大小，进行分割节点操作，剩余的节点重新挂载到相应的空闲链表上。如果对应的空闲链表为空，则向更大的内存区间去查询是否有满足条件的空闲链表，实际计算时，会一次性查找到满足申请大小的空闲链表。

内存管理结构如下图所示：

  **图3** 轻量系统动态内存管理结构图
  
  ![zh-cn_image_0000001153313284](figures/zh-cn_image_0000001153313284.png)

- 内存池池头部分
  内存池池头部分包含内存池信息、位图标记数组和空闲链表数组。内存池信息包含内存池起始地址及堆区域总大小，内存池属性。位图标记数组有7个32位无符号整数组成，每个比特位标记对应的空闲链表是否挂载空闲内存块节点。空闲内存链表包含223个空闲内存头节点信息，每个空闲内存头节点信息维护内存节点头和空闲链表中的前驱、后继空闲内存节点。

- 内存池节点部分
  包含3种类型节点：未使用空闲内存节点，已使用内存节点和尾节点。每个内存节点维护一个前序指针，指向内存池中上一个内存节点，还维护内存节点的大小和使用标记。空闲内存节点和已使用内存节点后面的内存区域是数据域，尾节点没有数据域。

一些芯片片内RAM大小无法满足要求，需要使用片外物理内存进行扩充。对于这样的多段非连续性内存， LiteOS-M内核支持把多个非连续性内存逻辑上合一，用户不感知底层的多段非连续性内存区域。 LiteOS-M内核内存模块把不连续的内存区域作为空闲内存结点插入到空闲内存节点链表，把不同内存区域间的不连续部分标记为虚拟的已使用内存节点，从逻辑上把多个非连续性内存区域实现为一个统一的内存池。下面通过示意图说明下多段非连续性内存的运行机制：
  **图4** 非连续性内存合一示意图
  ![zh-cn_image_0000001198253551](figures/zh-cn_image_0000001198253551.png)

结合上述示意图，非连续性内存合并为一个统一的内存池的步骤如下：

1. 把多段非连续性内存区域的第一块内存区域通过调用LOS_MemInit接口进行初始化。

2. 获取下一个内存区域的开始地址和长度，计算该内存区域和上一块内存区域的间隔大小gapSize。

3. 把内存区域间隔部分视为虚拟的已使用节点，使用上一个内存区域的尾节点，设置其大小为gapSize + OS_MEM_NODE_HEAD_SIZE（即sizeof(struct OsMemUsedNodeHead)）。

4. 把当前内存区域划分为一个空闲内存节点和一个尾节点，把空闲内存节点插入到空闲链表，并设置各个节点的前后链接关系。

5. 如果有更多的非连续内存区域，重复上述步骤2-4。


### 开发指导


#### 使用场景

动态内存管理的主要工作是动态分配并管理用户申请到的内存区间。动态内存管理主要用于用户需要使用大小不等的内存块的场景，当用户需要使用内存时，可以通过操作系统的动态内存申请函数索取指定大小的内存块，一旦使用完毕，通过动态内存释放函数归还所占用内存，使之可以重复使用。


#### 接口说明

OpenHarmony LiteOS-M的动态内存管理主要为用户提供以下功能，接口详细信息可以查看API参考。

  **表1** 动态内存模块接口

| 功能分类 | 接口描述 |
| -------- | -------- |
| 初始化和删除内存池 | &nbsp;LOS_MemInit：初始化一块指定的动态内存池，大小为size。<br/>&nbsp;LOS_MemDeInit：删除指定内存池，仅打开编译控制开关LOSCFG_MEM_MUL_POOL时有效。 |
| 申请、释放动态内存 | &nbsp;LOS_MemAlloc：从指定动态内存池中申请size长度的内存。<br/>&nbsp;LOS_MemFree：释放从指定动态内存中申请的内存。<br/>&nbsp;LOS_MemRealloc：释放从指定动态内存中申请的内存。 |
| 获取内存池信息 | &nbsp;LOS_MemPoolSizeGet：获取指定动态内存池的总大小。<br/>&nbsp;LOS_MemTotalUsedGet：获取指定动态内存池的总使用量大小。<br/>&nbsp;LOS_MemInfoGet：获取指定内存池的内存结构信息，包括空闲内存大小、已使用内存大小、空闲内存块数量、已使用的内存块数量、最大的空闲内存块大小。<br/>&nbsp;LOS_MemPoolList：打印系统中已初始化的所有内存池，包括内存池的起始地址、内存池大小、空闲内存总大小、已使用内存总大小、最大的空闲内存块大小、空闲内存块数量、已使用的内存块数量。仅打开编译控制开关LOSCFG_MEM_MUL_POOL时有效。 |
| 获取内存块信息 | &nbsp;LOS_MemFreeNodeShow：打印指定内存池的空闲内存块的大小及数量。<br/>&nbsp;LOS_MemUsedNodeShow：打印指定内存池的已使用内存块的大小及数量。 |
| 检查指定内存池的完整性 | LOS_MemIntegrityCheck：对指定内存池做完整性检查，仅打开编译控制开关LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK时有效。 |
| 增加非连续性内存区域 | LOS_MemRegionsAdd：支持多段非连续性内存区域，把非连续性内存区域逻辑上整合为一个统一的内存池。仅打开LOSCFG_MEM_MUL_REGIONS时有效。如果内存池指针参数pool为空，则使用多段内存的第一个初始化为内存池，其他内存区域，作为空闲节点插入；如果内存池指针参数pool不为空，则把多段内存作为空闲节点，插入到指定的内存池。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 由于动态内存管理需要管理控制块数据结构来管理内存，这些数据结构会额外消耗内存，故实际用户可使用内存总量小于配置项OS_SYS_MEM_SIZE的大小。
> 
> - 对齐分配内存接口LOS_MemAllocAlign/LOS_MemMallocAlign因为要进行地址对齐，可能会额外消耗部分内存，故存在一些遗失内存，当系统释放该对齐内存时，同时回收由于对齐导致的遗失内存。
> 
> - 非连续性内存区域接口LOS_MemRegionsAdd的LosMemRegion数组参数传入的非连续性内存区域需要按各个内存区域的内存开始地址升序，且内存区域不能重叠。


#### 开发流程

本节介绍使用动态内存的典型场景开发流程。

1. 初始化LOS_MemInit。
   初始一个内存池后生成一个内存池控制头、尾节点EndNode，剩余的内存被标记为FreeNode内存节点。注：EndNode作为内存池末尾的节点，size为0。

1. 申请任意大小的动态内存LOS_MemAlloc。
   判断动态内存池中是否存在大于申请量大小的空闲内存块空间，若存在，则划出一块内存块，以指针形式返回，若不存在，返回NULL。如果空闲内存块大于申请量，需要对内存块进行分割，剩余的部分作为空闲内存块挂载到空闲内存链表上。

1. 释放动态内存LOS_MemFree。
   回收内存块，供下一次使用。调用LOS_MemFree释放内存块，则会回收内存块，并且将其标记为FreeNode。在回收内存块时，相邻的FreeNode会自动合并。


#### 编程实例

本实例执行以下步骤：

1. 初始化一个动态内存池。

2. 从动态内存池中申请一个内存块。

3. 在内存块中存放一个数据。

4. 打印出内存块中的数据。

5. 释放该内存块。

示例代码如下：

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数ExampleDynMem。


```
#include "los_memory.h"

#define TEST_POOL_SIZE (2*1024)
#define MEMBOX_WR_TEST_NUM  828

__attribute__((aligned(4))) UINT8 g_testDynPool[TEST_POOL_SIZE];

VOID ExampleDynMem(VOID)
{
    UINT32 *mem = NULL;
    UINT32 ret;

    /* 初始化内存池 */
    ret = LOS_MemInit(g_testDynPool, TEST_POOL_SIZE);
    if (LOS_OK  == ret) {
        printf("Mem init success!\n");
    } else {
        printf("Mem init failed!\n");
        return;
    }

    /* 申请内存块 */
    mem = (UINT32 *)LOS_MemAlloc(g_testDynPool, 4);
    if (mem == NULL) {
        printf("Mem alloc failed!\n");
        return;
    }
    printf("Mem alloc success!\n");

    /* 内存地址读写验证 */
    *mem = MEMBOX_WR_TEST_NUM;
    printf("*mem = %d\n", *mem);

    /* 释放内存 */
    ret = LOS_MemFree(g_testDynPool, mem);
    if (LOS_OK == ret) {
        printf("Mem free success!\n");
    } else {
        printf("Mem free failed!\n");
    }

    return;
}
```


#### 结果验证

输出结果如下：


```
Mem init success!
Mem alloc success!
*mem = 828
Mem free success!
```
