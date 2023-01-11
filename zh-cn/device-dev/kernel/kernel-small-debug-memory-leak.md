# 内存泄漏检测


## 基础概念

内存泄漏检测机制作为内核的可选功能，用于辅助定位动态内存泄漏问题。开启该动能，动态内存机制会自动记录申请内存时的函数调用关系（下文简称LR）。如果出现泄漏，就可以利用这些记录的信息，找到内存申请的地方，方便进一步确认。


## 功能配置

1. LOSCFG_MEM_LEAKCHECK：开关宏，默认关闭；如需要打开这个功能，可以在配置项中开启“Debug-&gt; Enable Function call stack of Mem operation recorded”。

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


该示例代码的测试函数可以加在 kernel /liteos_a/testsuites /kernel /src /osTest.c  中的 TestTaskEntry 中进行测试.
代码实现如下：

```c
#include <stdio.h>
#include <string.h>
#include "los_memory.h"
#include "los_config.h"

void MemLeakTest(void)
{
    OsMemUsedNodeShow(LOSCFG_SYS_HEAP_ADDR);
    void *ptr1 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    void *ptr2 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    OsMemUsedNodeShow(LOSCFG_SYS_HEAP_ADDR);
}
```


**结果验证**


编译运行输出log如下：

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
```


对比两次log，差异如下，这些内存节点就是疑似泄漏的内存块：

```
0x20003ac4:  0x1d   0x08001458  0x080014e0  0x080041e6
0x20003ae0:  0x1d   0x080041ee  0x08000cc2  0x00000000
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
```


其中，通过查找0x080041ee，就可以发现该内存节点是在MemLeakTest接口里申请的且是没有释放的。
