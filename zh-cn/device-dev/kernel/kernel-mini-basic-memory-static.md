# 静态内存


## 运行机制

静态内存实质上是一个静态数组，静态内存池内的块大小在初始化时设定，初始化后块大小不可变更。

静态内存池由一个控制块LOS_MEMBOX_INFO和若干相同大小的内存块LOS_MEMBOX_NODE构成。控制块位于内存池头部，用于内存块管理，包含内存块大小uwBlkSize，内存块数量uwBlkNum，已分配使用的内存块数量uwBlkCnt和空闲内存块链表stFreeList。内存块的申请和释放以块大小为粒度，每个内存块包含指向下一个内存块的指针pstNext。

  **图1** 静态内存示意图
  ![zh-cn_image_0000001199352039](figures/zh-cn_image_0000001199352039.png)


## 开发指导


### 使用场景

当用户需要使用固定长度的内存时，可以通过静态内存分配的方式获取内存，一旦使用完毕，通过静态内存释放函数归还所占用内存，使之可以重复使用。


### 接口说明

OpenHarmony LiteOS-M的静态内存管理主要为用户提供以下功能，接口详细信息可以查看API参考。

  **表1** 静态内存模块接口

| 功能分类 | 接口名 | 
| -------- | -------- |
| 初始化静态内存池 | LOS_MemboxInit：初始化一个静态内存池，根据入参设定其起始地址、总大小及每个内存块大小。 | 
| 清除静态内存块内容 | LOS_MemboxClr:清零从静态内存池中申请的静态内存块的内容。 | 
| 申请、释放静态内存 | -&nbsp;LOS_MemboxAlloc：从指定的静态内存池中申请一块静态内存块。<br/>-&nbsp;LOS_MemboxFree：释放从静态内存池中申请的一块静态内存块。 | 
| 获取、打印静态内存池信息 | -&nbsp;LOS_MemboxStatisticsGet:获取指定静态内存池的信息，包括内存池中总内存块数量、已经分配出去的内存块数量、每个内存块的大小。<br/>-&nbsp;LOS_ShowBox:打印指定静态内存池所有节点信息（打印等级是LOS_INFO_LEVEL），包括内存池起始地址、内存块大小、总内存块数量、每个空闲内存块的起始地址、所有内存块的起始地址。 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 初始化后的内存池的内存块数量，不等于总大小除于内存块大小，因为内存池的控制块和每个内存块的控制头，都存在内存开销，设置总大小时，需要将这些因素考虑进去。


### 开发流程

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


### 编程实例

本实例执行以下步骤：

1. 初始化一个静态内存池。

2. 从静态内存池中申请一块静态内存。

3. 在内存块存放一个数据。

4. 打印出内存块中的数据。

5. 清除内存块中的数据。

6. 释放该内存块。
   示例代码如下：

  
```
#include "los_membox.h"

VOID Example_StaticMem(VOID)
{
    UINT32 *mem = NULL;
    UINT32 blkSize = 10;
    UINT32 boxSize = 100;
    UINT32 boxMem[1000];
    UINT32 ret;

    /*内存池初始化*/
    ret = LOS_MemboxInit(&boxMem[0], boxSize, blkSize);
    if(ret != LOS_OK) {
        printf("Membox init failed!\n");
        return;
    } else {
        printf("Membox init success!\n");
    }

    /*申请内存块*/
    mem = (UINT32 *)LOS_MemboxAlloc(boxMem);
    if (NULL == mem) {
        printf("Mem alloc failed!\n");
        return;
    }
    printf("Mem alloc success!\n");

    /*赋值*/
    *mem = 828;
    printf("*mem = %d\n", *mem);

    /*清除内存内容*/
    LOS_MemboxClr(boxMem, mem);
    printf("Mem clear success \n *mem = %d\n", *mem);

    /*释放内存*/
    ret = LOS_MemboxFree(boxMem, mem);
    if (LOS_OK == ret) {
        printf("Mem free success!\n");
    } else {
        printf("Mem free failed!\n");
    }

    return;
}
```


### 结果验证

输出结果如下：

  
```
Membox init success!
Mem alloc success!
*mem = 828
Mem clear success   
*mem = 0
Mem free success!
```
