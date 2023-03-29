# 踩内存检测


## 基础概念

踩内存检测机制作为内核的可选功能，用于检测动态内存池的完整性。通过该机制，可以及时发现内存池是否发生了踩内存问题，并给出错误信息，便于及时发现系统问题，提高问题解决效率，降低问题定位成本。


## 功能配置

LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK：开关宏，默认关闭；若打开这个功能，可以在配置项中开启“Debug-&gt; Enable integrity check or not”。

1、开启这个功能，每次申请内存，会实时检测内存池的完整性。

2、如果不开启该功能，也可以调用LOS_MemIntegrityCheck接口检测，但是每次申请内存时，不会实时检测内存完整性，而且由于节点头没有魔鬼数字（开启时才有，省内存），检测的准确性也会相应降低，但对于系统的性能没有影响，故根据实际情况开关该功能。

由于该功能只会检测出哪个内存节点被破坏了，并给出前节点信息（因为内存分布是连续的，当前节点最有可能被前节点破坏）。如果要进一步确认前节点在哪里申请的，需开启内存泄漏检测功能，通过LR记录，辅助定位。

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> 开启该功能，节点头多了魔鬼数字字段，会增大节点头大小。由于实时检测完整性，故性能影响较大；若性能敏感的场景，可以不开启该功能，使用LOS_MemIntegrityCheck接口检测。


## 开发指导


### 开发流程

通过调用LOS_MemIntegrityCheck接口检测内存池是否发生了踩内存，如果没有踩内存问题，那么接口返回0且没有log输出；如果存在踩内存问题，那么会输出相关log，详见下文编程实例的结果输出。


### 编程实例

本实例实现如下功能：

1. 申请两个物理上连续的内存块；

2. 通过memset构造越界访问，踩到下个节点的头4个字节；

3. 调用LOS_MemIntegrityCheck检测是否发生踩内存。


**示例代码**


该示例代码的测试函数可以加在 kernel /liteos_a/testsuites /kernel /src /osTest.c  中的 TestTaskEntry 中进行测试.
代码实现如下：



```c
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


**结果验证**


编译运行输出log如下：



```
[ERR][OsMemMagicCheckPrint], 2028, memory check error!
memory used but magic num wrong, magic num = 0x00000000   /* 提示信息，检测到哪个字段被破坏了，用例构造了将下个节点的头4个字节清零，即魔鬼数字字段 */

 broken node head: 0x20003af0  0x00000000  0x80000020, prev node head: 0x20002ad4  0xabcddcba  0x80000020
/* 被破坏节点和其前节点关键字段信息，分别为其前节点地址、节点的魔鬼数字、节点的sizeAndFlag；可以看出被破坏节点的魔鬼数字字段被清零，符合用例场景 */

 broken node head LR info:  /* 节点的LR信息需要开启内存检测功能才有有效输出 */
 LR[0]:0x0800414e
 LR[1]:0x08000cc2
 LR[2]:0x00000000

 pre node head LR info:   /* 通过LR信息，可以在汇编文件中查找前节点是哪里申请，然后排查其使用的准确性 */
 LR[0]:0x08004144
 LR[1]:0x08000cc2
 LR[2]:0x00000000
[ERR]Memory interity check error, cur node: 0x20003b10, pre node: 0x20003af0   /* 被破坏节点和其前节点的地址 */
```
