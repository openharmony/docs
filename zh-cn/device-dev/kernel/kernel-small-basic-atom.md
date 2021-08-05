# 原子操作<a name="ZH-CN_TOPIC_0000001078876272"></a>

-   [基本概念](#section1792118384594)
-   [运行机制](#section1786635117596)
-   [开发指导](#section2911115308)
    -   [接口说明](#section335914201010)
    -   [开发流程](#section12207371304)
    -   [编程实例](#section8538651511)


## 基本概念<a name="section1792118384594"></a>

在支持多任务的操作系统中，修改一块内存区域的数据需要“读取-修改-写入”三个步骤。然而同一内存区域的数据可能同时被多个任务访问，如果在修改数据的过程中被其他任务打断，就会造成该操作的执行结果无法预知。

使用开关中断的方法固然可以保证多任务执行结果符合预期，但是显然这种方法会影响系统性能。

ARMv6架构引入了LDREX和STREX指令，以支持对共享存储器更缜密的非阻塞同步。由此实现的原子操作能确保对同一数据的“读取-修改-写入”操作在它的执行期间不会被打断，即操作的原子性。

## 运行机制<a name="section1786635117596"></a>

OpenHarmony系统通过对ARMv6架构中的LDREX和STREX进行封装，向用户提供了一套原子性的操作接口。

-   LDREX Rx, \[Ry\]

    读取内存中的值，并标记对该段内存的独占访问：

    -   读取寄存器Ry指向的4字节内存数据，保存到Rx寄存器中。
    -   对Ry指向的内存区域添加独占访问标记。

-   STREX Rf, Rx, \[Ry\]

    检查内存是否有独占访问标记，如果有则更新内存值并清空标记，否则不更新内存：

    -   有独占访问标记
        -   将寄存器Rx中的值更新到寄存器Ry指向的内存。
        -   标志寄存器Rf置为0。

    -   没有独占访问标记
        -   不更新内存。
        -   标志寄存器Rf置为1。


-   判断标志寄存器
    -   标志寄存器为0时，退出循环，原子操作结束。
    -   标志寄存器为1时，继续循环，重新进行原子操作。


## 开发指导<a name="section2911115308"></a>

### 接口说明<a name="section335914201010"></a>

OpenHarmony LiteOS-A内核的原子操作模块提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  原子操作接口说明

<a name="table29217519171"></a>
<table><thead align="left"><tr id="row79375119172"><th class="cellrowborder" valign="top" width="21.21212121212121%" id="mcps1.2.4.1.1"><p id="p159375113174"><a name="p159375113174"></a><a name="p159375113174"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.39333933393339%" id="mcps1.2.4.1.2"><p id="p199385118173"><a name="p199385118173"></a><a name="p199385118173"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="45.3945394539454%" id="mcps1.2.4.1.3"><p id="p18937511175"><a name="p18937511175"></a><a name="p18937511175"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row159315151712"><td class="cellrowborder" rowspan="2" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p593135115176"><a name="p593135115176"></a><a name="p593135115176"></a>读</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p1193651181714"><a name="p1193651181714"></a><a name="p1193651181714"></a>LOS_AtomicRead</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p09316512178"><a name="p09316512178"></a><a name="p09316512178"></a>读取32bit原子数据</p>
</td>
</tr>
<tr id="row1493151161719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p119395111718"><a name="p119395111718"></a><a name="p119395111718"></a>LOS_Atomic64Read</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p49311514178"><a name="p49311514178"></a><a name="p49311514178"></a>读取64bit原子数据</p>
</td>
</tr>
<tr id="row69365111712"><td class="cellrowborder" rowspan="2" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p199355111175"><a name="p199355111175"></a><a name="p199355111175"></a>写</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p1693175191714"><a name="p1693175191714"></a><a name="p1693175191714"></a>LOS_AtomicSet</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p129320516173"><a name="p129320516173"></a><a name="p129320516173"></a>设置32bit原子数据</p>
</td>
</tr>
<tr id="row1593651111718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7944510176"><a name="p7944510176"></a><a name="p7944510176"></a>LOS_Atomic64Set</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p294115191713"><a name="p294115191713"></a><a name="p294115191713"></a>设置64bit原子数据</p>
</td>
</tr>
<tr id="row149495114177"><td class="cellrowborder" rowspan="6" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p1394165151718"><a name="p1394165151718"></a><a name="p1394165151718"></a>加</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p494115112179"><a name="p494115112179"></a><a name="p494115112179"></a>LOS_AtomicAdd</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p1694155120174"><a name="p1694155120174"></a><a name="p1694155120174"></a>对32bit原子数据做加法</p>
</td>
</tr>
<tr id="row394651101719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p179435113171"><a name="p179435113171"></a><a name="p179435113171"></a>LOS_Atomic64Add</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p594851181718"><a name="p594851181718"></a><a name="p594851181718"></a>对64bit原子数据做加法</p>
</td>
</tr>
<tr id="row294185110171"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1834102212615"><a name="p1834102212615"></a><a name="p1834102212615"></a>LOS_AtomicInc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p129413519173"><a name="p129413519173"></a><a name="p129413519173"></a>对32bit原子数据做加1</p>
</td>
</tr>
<tr id="row1894175101713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1981302213264"><a name="p1981302213264"></a><a name="p1981302213264"></a>LOS_Atomic64Inc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p167671640113316"><a name="p167671640113316"></a><a name="p167671640113316"></a>对64bit原子数据做加1</p>
</td>
</tr>
<tr id="row12946512178"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1994051181716"><a name="p1994051181716"></a><a name="p1994051181716"></a>LOS_AtomicIncRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p59414511172"><a name="p59414511172"></a><a name="p59414511172"></a>对32bit原子数据做加1并返回</p>
</td>
</tr>
<tr id="row1994551101712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p129414519173"><a name="p129414519173"></a><a name="p129414519173"></a>LOS_Atomic64IncRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1194951111713"><a name="p1194951111713"></a><a name="p1194951111713"></a>对64bit原子数据做加1并返回</p>
</td>
</tr>
<tr id="row1794451121719"><td class="cellrowborder" rowspan="6" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p179412517173"><a name="p179412517173"></a><a name="p179412517173"></a>减</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p89495115176"><a name="p89495115176"></a><a name="p89495115176"></a>LOS_AtomicSub</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p18220416345"><a name="p18220416345"></a><a name="p18220416345"></a>对32bit原子数据做减法</p>
</td>
</tr>
<tr id="row139485131718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1894195116176"><a name="p1894195116176"></a><a name="p1894195116176"></a>LOS_Atomic64Sub</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20822124173415"><a name="p20822124173415"></a><a name="p20822124173415"></a>对64bit原子数据做减法</p>
</td>
</tr>
<tr id="row209505110175"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7951051141713"><a name="p7951051141713"></a><a name="p7951051141713"></a>LOS_AtomicDec</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p382234117340"><a name="p382234117340"></a><a name="p382234117340"></a>对32bit原子数据做减1</p>
</td>
</tr>
<tr id="row995151171711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p395151131715"><a name="p395151131715"></a><a name="p395151131715"></a>LOS_Atomic64Dec</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1982244117340"><a name="p1982244117340"></a><a name="p1982244117340"></a>对64bit原子数据做减1</p>
</td>
</tr>
<tr id="row895155117179"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p395155151719"><a name="p395155151719"></a><a name="p395155151719"></a>LOS_AtomicDecRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p198222414349"><a name="p198222414349"></a><a name="p198222414349"></a>对32bit原子数据做减1并返回</p>
</td>
</tr>
<tr id="row59511518170"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1495125119175"><a name="p1495125119175"></a><a name="p1495125119175"></a>LOS_Atomic64DecRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p198221841103419"><a name="p198221841103419"></a><a name="p198221841103419"></a>对64bit原子数据做减1并返回</p>
</td>
</tr>
<tr id="row159575131714"><td class="cellrowborder" rowspan="4" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p159585110177"><a name="p159585110177"></a><a name="p159585110177"></a>交换</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p29515114174"><a name="p29515114174"></a><a name="p29515114174"></a>LOS_AtomicXchgByte</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p6956510177"><a name="p6956510177"></a><a name="p6956510177"></a>交换8bit内存数据</p>
</td>
</tr>
<tr id="row14951451111710"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8952514173"><a name="p8952514173"></a><a name="p8952514173"></a>LOS_AtomicXchg16bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12334173143919"><a name="p12334173143919"></a><a name="p12334173143919"></a>交换16bit内存数据</p>
</td>
</tr>
<tr id="row595251131716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1495145117171"><a name="p1495145117171"></a><a name="p1495145117171"></a>LOS_AtomicXchg32bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9951513173"><a name="p9951513173"></a><a name="p9951513173"></a>交换32bit内存数据</p>
</td>
</tr>
<tr id="row195165131718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18951151141717"><a name="p18951151141717"></a><a name="p18951151141717"></a>LOS_AtomicXchg64bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p169685115172"><a name="p169685115172"></a><a name="p169685115172"></a>交换64bit内存数据</p>
</td>
</tr>
<tr id="row149616511175"><td class="cellrowborder" rowspan="4" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p49615120172"><a name="p49615120172"></a><a name="p49615120172"></a>先比较后交换</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p129605112171"><a name="p129605112171"></a><a name="p129605112171"></a>LOS_AtomicCmpXchgByte</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p6965510178"><a name="p6965510178"></a><a name="p6965510178"></a>比较相同后交换8bit内存数据</p>
</td>
</tr>
<tr id="row99605171713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p109675131711"><a name="p109675131711"></a><a name="p109675131711"></a>LOS_AtomicCmpXchg16bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17961951191719"><a name="p17961951191719"></a><a name="p17961951191719"></a>比较相同后交换16bit内存数据</p>
</td>
</tr>
<tr id="row169614513177"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p49645115172"><a name="p49645115172"></a><a name="p49645115172"></a>LOS_AtomicCmpXchg32bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p129611512175"><a name="p129611512175"></a><a name="p129611512175"></a>比较相同后交换32bit内存数据</p>
</td>
</tr>
<tr id="row696175110179"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16961051161715"><a name="p16961051161715"></a><a name="p16961051161715"></a>LOS_AtomicCmpXchg64bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1296205118179"><a name="p1296205118179"></a><a name="p1296205118179"></a>比较相同后交换64bit内存数据</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section12207371304"></a>

有多个任务对同一个内存数据进行加减或交换等操作时，使用原子操作保证结果的可预知性。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>原子操作接口仅支持整型数据。

### 编程实例<a name="section8538651511"></a>

**实例描述**

调用原子操作相关接口，观察结果：

1.  创建两个任务
    -   任务一用LOS\_AtomicInc对全局变量加100次。
    -   任务二用LOS\_AtomicDec对全局变量减100次。

2.  子任务结束后在主任务中打印全局变量的值。

**示例代码**

示例代码如下：

```
#include "los_hwi.h"
#include "los_atomic.h"
#include "los_task.h"

UINT32 g_testTaskId01;
UINT32 g_testTaskId02;
Atomic g_sum;
Atomic g_count;

UINT32 Example_Atomic01(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicInc(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_Atomic02(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicDec(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_AtomicTaskEntry(VOID)
{
    TSK_INIT_PARAM_S stTask1={0};
    stTask1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic01;
    stTask1.pcName       = "TestAtomicTsk1";
    stTask1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask1.usTaskPrio   = 4;
    stTask1.uwResved     = LOS_TASK_STATUS_DETACHED;

    TSK_INIT_PARAM_S stTask2={0};
    stTask2.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic02;
    stTask2.pcName       = "TestAtomicTsk2";
    stTask2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask2.usTaskPrio   = 4;
    stTask2.uwResved     = LOS_TASK_STATUS_DETACHED;

    LOS_TaskLock();
    LOS_TaskCreate(&g_testTaskId01, &stTask1);
    LOS_TaskCreate(&g_testTaskId02, &stTask2);
    LOS_TaskUnlock();

    while(LOS_AtomicRead(&g_count) != 2);
    PRINTK("g_sum = %d\n", g_sum);

    return LOS_OK;
}
```

**结果验证**

```
g_sum = 0
```

