# 开发指导<a name="ZH-CN_TOPIC_0000001078876508"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section460018317164)
    -   [实例描述](#section896412438910)
    -   [示例代码](#section149077554912)
    -   [结果验证](#section4461439172017)


## 接口说明<a name="section158501652121514"></a>

<a name="table14277123518139"></a>
<table><thead align="left"><tr id="row152771935131315"><th class="cellrowborder" valign="top" width="17.77177717771777%" id="mcps1.1.4.1.1"><p id="p1127733591316"><a name="p1127733591316"></a><a name="p1127733591316"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="22.932293229322934%" id="mcps1.1.4.1.2"><p id="p22771357138"><a name="p22771357138"></a><a name="p22771357138"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="59.2959295929593%" id="mcps1.1.4.1.3"><p id="p327714358130"><a name="p327714358130"></a><a name="p327714358130"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1627793517136"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p10525141151410"><a name="p10525141151410"></a><a name="p10525141151410"></a>事件检测</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p1027783551315"><a name="p1027783551315"></a><a name="p1027783551315"></a>LOS_EventPoll</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p1717215119159"><a name="p1717215119159"></a><a name="p1717215119159"></a>根据eventID，eventMask（事件掩码），mode（事件读取模式），检查用户期待的事件是否发生。</p>
<div class="notice" id="note29631113132915"><a name="note29631113132915"></a><a name="note29631113132915"></a><span class="noticetitle"> 须知： </span><div class="noticebody"><p id="p886616817302"><a name="p886616817302"></a><a name="p886616817302"></a>当mode含LOS_WAITMODE_CLR，且用户期待的事件发生时，此时eventID中满足要求的事件会被清零，这种情况下eventID既是入参也是出参。其他情况eventID只作为入参。</p>
</div></div>
</td>
</tr>
<tr id="row20278035131316"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p135816209511"><a name="p135816209511"></a><a name="p135816209511"></a>初始化</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p5361103903417"><a name="p5361103903417"></a><a name="p5361103903417"></a>LOS_EventInit</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p1936143993419"><a name="p1936143993419"></a><a name="p1936143993419"></a>事件控制块初始化。</p>
</td>
</tr>
<tr id="row1736713145208"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p65802020512"><a name="p65802020512"></a><a name="p65802020512"></a>事件读</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p1436015394341"><a name="p1436015394341"></a><a name="p1436015394341"></a>LOS_EventRead</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p1935911398345"><a name="p1935911398345"></a><a name="p1935911398345"></a>读事件（等待事件），任务会根据timeOut（单位：tick）进行阻塞等待；</p>
<p id="p624360131813"><a name="p624360131813"></a><a name="p624360131813"></a>未读取到事件时，返回值为0；</p>
<p id="p825491321911"><a name="p825491321911"></a><a name="p825491321911"></a>正常读取到事件时，返回正值（事件发生的集合）；</p>
<p id="p262373895217"><a name="p262373895217"></a><a name="p262373895217"></a>其他情况返回特定错误码。</p>
</td>
</tr>
<tr id="row19475718122016"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p18580201754"><a name="p18580201754"></a><a name="p18580201754"></a>事件写</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p1135843933412"><a name="p1135843933412"></a><a name="p1135843933412"></a>LOS_EventWrite</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p526932914325"><a name="p526932914325"></a><a name="p526932914325"></a>写一个特定的事件到事件控制块。</p>
</td>
</tr>
<tr id="row913918371962"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p13581201655"><a name="p13581201655"></a><a name="p13581201655"></a>事件清除</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p12140137165"><a name="p12140137165"></a><a name="p12140137165"></a>LOS_EventClear</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p19140637968"><a name="p19140637968"></a><a name="p19140637968"></a>根据events掩码，清除事件控制块中的事件。</p>
</td>
</tr>
<tr id="row1173017715"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p1458102010519"><a name="p1458102010519"></a><a name="p1458102010519"></a>事件销毁</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p31740171"><a name="p31740171"></a><a name="p31740171"></a>LOS_EventDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p17171501971"><a name="p17171501971"></a><a name="p17171501971"></a>事件控制块销毁。</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

事件的典型开发流程：

1.  初始化事件控制块
2.  阻塞读事件控制块
3.  写入相关事件
4.  阻塞任务被唤醒，读取事件并检查是否满足要求
5.  处理事件控制块
6.  事件控制块销毁

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   进行事件读写操作时，事件的第25位为保留位，不可以进行位设置。
>-   对同一事件反复写入，算作一次写入。

## 编程实例<a name="section460018317164"></a>

### 实例描述<a name="section896412438910"></a>

示例中，任务Example\_TaskEntry创建一个任务Example\_Event，Example\_Event读事件阻塞，Example\_TaskEntry向该任务写事件。可以通过示例日志中打印的先后顺序理解事件操作时伴随的任务切换。

1.  在任务Example\_TaskEntry创建任务Example\_Event，其中任务Example\_Event优先级高于Example\_TaskEntry。
2.  在任务Example\_Event中读事件0x00000001，阻塞，发生任务切换，执行任务Example\_TaskEntry。
3.  在任务Example\_TaskEntry向任务Example\_Event写事件0x00000001，发生任务切换，执行任务Example\_Event。
4.  Example\_Event得以执行，直到任务结束。
5.  Example\_TaskEntry得以执行，直到任务结束。

### 示例代码<a name="section149077554912"></a>

示例代码如下：

```
#include "los_event.h"
#include "los_task.h"
#include "securec.h"

/* 任务ID */
UINT32 g_testTaskId;

/* 事件控制结构体 */
EVENT_CB_S g_exampleEvent;

/* 等待的事件类型 */
#define EVENT_WAIT 0x00000001

/* 用例任务入口函数 */
VOID Example_Event(VOID)
{
    UINT32 ret;
    UINT32 event;

    /* 超时等待方式读事件,超时时间为100 ticks, 若100 ticks后未读取到指定事件，读事件超时，任务直接唤醒 */
    printf("Example_Event wait event 0x%x \n", EVENT_WAIT);

    event = LOS_EventRead(&g_exampleEvent, EVENT_WAIT, LOS_WAITMODE_AND, 100);
    if (event == EVENT_WAIT) {
        printf("Example_Event,read event :0x%x\n", event);
    } else {
        printf("Example_Event,read event timeout\n");
    }
}

UINT32 Example_TaskEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;

    /* 事件初始化 */
    ret = LOS_EventInit(&g_exampleEvent);
    if (ret != LOS_OK) {
        printf("init event failed .\n");
        return -1;
    }

    /* 创建任务 */
    (VOID)memset_s(&task1, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Event;
    task1.pcName       = "EventTsk1";
    task1.uwStackSize  = OS_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_testTaskId, &task1);
    if (ret != LOS_OK) {
        printf("task create failed.\n");
        return LOS_NOK;
    }

    /* 写g_testTaskId 等待事件 */
    printf("Example_TaskEntry write event.\n");

    ret = LOS_EventWrite(&g_exampleEvent, EVENT_WAIT);
    if (ret != LOS_OK) {
        printf("event write failed.\n");
        return LOS_NOK;
    }

    /* 清标志位 */
    printf("EventMask:%d\n", g_exampleEvent.uwEventID);
    LOS_EventClear(&g_exampleEvent, ~g_exampleEvent.uwEventID);
    printf("EventMask:%d\n", g_exampleEvent.uwEventID);

    /* 删除任务 */
    ret = LOS_TaskDelete(g_testTaskId);
    if (ret != LOS_OK) {
        printf("task delete failed.\n");
        return LOS_NOK;
    }

    return LOS_OK;
}
```

### 结果验证<a name="section4461439172017"></a>

编译运行得到的结果为：

```
Example_Event wait event 0x1 
Example_TaskEntry write event.
Example_Event,read event :0x1
EventMask:1
EventMask:0
```

