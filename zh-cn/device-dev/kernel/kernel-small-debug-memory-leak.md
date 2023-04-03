# 内存泄漏检测


## 基础概念

内存泄漏检测机制作为内核的可选功能，用于辅助定位动态内存泄漏问题。开启该动能，动态内存机制会自动记录申请内存时的函数调用关系（下文简称LR）。如果出现泄漏，就可以利用这些记录的信息，找到内存申请的地方，方便进一步确认。


## 功能配置

1. LOSCFG_MEM_LEAKCHECK：开关宏，默认关闭；如需要打开这个功能，可以在配置项中开启“Debug-&gt; Enable MEM Debug-&gt; Enable Function call stack of Mem operation recorded”。

2. LOS_RECORD_LR_CNT：记录的LR层数，默认3层；每层LR消耗sizeof(void \*)字节数的内存。

3. LOS_OMIT_LR_CNT：忽略的LR层数，默认2层，即从调用LOS_MemAlloc的函数开始记录，可根据实际情况调整。需要此配置原因如下：
   - LOS_MemAlloc接口内部也有函数调用；
   - 外部可能对LOS_MemAlloc接口有封装；
   - LOS_RECORD_LR_CNT 配置的LR层数有限；

正确配置这个宏，将无效的LR层数忽略，就可以记录有效的LR层数，节省内存消耗。


## 开发指导


### 开发流程

该调测功能可以分析关键的代码逻辑中是否存在内存泄漏。开启这个功能，每次申请内存时，会记录LR信息。在需要检测的代码段前后，调用LOS_MemUsedNodeShow接口，每次都会打印指定内存池已使用的全部节点信息，对比前后两次的节点信息，新增的节点信息就是疑似泄漏的内存节点。通过LR，可以找到具体申请的代码位置，进一步确认是否泄漏。

调用LOS_MemUsedNodeShow接口输出的节点信息格式如下：每1行为一个节点信息；第1列为节点地址，可以根据这个地址，使用GDB等工具查看节点完整信息；第2列为节点的大小，等于节点头大小+数据域大小；第3~5列为函数调用关系LR地址，可以根据这个值，结合汇编文件，查看该节点具体申请的位置。


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


### 编程实例

本实例实现如下功能：构建内存泄漏代码段。

1. 调用OsMemUsedNodeShow接口，输出全部节点信息打印；

2. 申请内存，但没有释放，模拟内存泄漏；

3. 再次调用OsMemUsedNodeShow接口，输出全部节点信息打印；

4. 将两次log进行对比，得出泄漏的节点信息；

5. 通过LR地址，找出泄漏的代码位置；


**示例代码**

本演示代码在 . kernel /liteos_a/testsuites /kernel /src /osTest.c中编译验证，在TestTaskEntry中调用验证入口函数MemLeakTest。

为了方便展示建议创建新的内存池，需要在target_config.h 中定义 LOSCFG_MEM_MUL_POOL

代码实现如下：

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

    /* 由于原内存池分配过多, 为了方便展示, 创建新的内存池 */
    pool = LOS_MemAlloc(OS_SYS_MEM_ADDR, TEST_NEW_POOL_SIZE);
    (VOID)LOS_MemInit(pool, TEST_NEW_POOL_SIZE);

    OsMemUsedNodeShow(pool);
    void *ptr1 = LOS_MemAlloc(pool, TEST_MALLOC_SIZE);
    void *ptr2 = LOS_MemAlloc(pool, TEST_MALLOC_SIZE);
    OsMemUsedNodeShow(pool);
    
    /* 释放内存池 */
    (VOID)LOS_MemDeInit(pool);
}
```


**结果验证**


编译运行输出log如下：

```
/* 第一次OsMemUsedNodeShow打印，由于该内存池未分配，所以无内存节点 */
node            LR[0]       LR[1]       LR[2]


/* 第二次OsMemUsedNodeShow打印，有两个新的内存节点 */
node            LR[0]       LR[1]       LR[2]
0x00402e0d90:  0x004009f040  0x0040037614  0x0040005480
0x00402e0db0:  0x004009f04c  0x0040037614  0x0040005480

```


对比两次log，差异如下，这些内存节点就是疑似泄漏的内存块：

```
0x00402e0d90:  0x004009f040  0x0040037614  0x0040005480
0x00402e0db0:  0x004009f04c  0x0040037614  0x0040005480
```


部分汇编文件如下:

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


其中，通过查找0x4009f040，就可以发现该内存节点是在MemLeakTest接口里申请的且是没有释放的。
