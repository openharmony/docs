# CPU占用率<a name="ZH-CN_TOPIC_0000001123188477"></a>

-   [基本概念](#section17683419227)
-   [运行机制](#section593718536227)
-   [开发指导](#section11284210152311)
    -   [接口说明](#section3745151592312)
    -   [开发流程](#section122901429182316)
    -   [编程实例](#section1765785212310)


## 基本概念<a name="section17683419227"></a>

CPU（中央处理器，Central Processing  Unit）占用率分为系统CPU占用率、进程CPU占用率、任务CPU占用率和中断CPU占用率。用户通过系统级的CPU占用率，判断当前系统负载是否超出设计规格。通过系统中各个进程/任务/中断的CPU占用情况，判断各个进程/任务/中断的CPU占用率是否符合设计的预期。

-   系统CPU占用率（CPU  Percent）

    指周期时间内系统的CPU占用率，用于表示系统一段时间内的闲忙程度，也表示CPU的负载情况。系统CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分比。100表示系统满负荷运转。

-   进程CPU占用率

    指单个进程的CPU占用率，用于表示单个进程在一段时间内的闲忙程度。进程CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分比。100表示在一段时间内系统一直在运行该进程。

-   任务CPU占用率

    指单个任务的CPU占用率，用于表示单个任务在一段时间内的闲忙程度。任务CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分比。100表示在一段时间内系统一直在运行该任务。

-   中断CPU占用率

    指单个中断的CPU占用率，用于表示单个中断在一段时间内的闲忙程度。中断CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分比。100表示在一段时间内系统一直在运行该中断。


## 运行机制<a name="section593718536227"></a>

OpenHarmony LiteOS-A内核CPUP（CPU  Percent，CPU占用率）模块采用进程、任务和中断级记录的方式，在进程/任务切换时，记录进程/任务启动时间，进程/任务切出或者退出时，系统会累加整个进程/任务的占用时间; 在执行中断时系统会累加记录每个中断的执行时间。

OpenHarmony 提供以下四种CPU占用率的信息查询：

-   系统CPU占用率
-   进程CPU占用率
-   任务CPU占用率
-   中断CPU占用率

**CPU占用率的计算方法：**

系统CPU占用率=系统中除idle任务外其他任务运行总时间/系统运行总时间

进程CPU占用率=进程运行总时间/系统运行总时间

任务CPU占用率=任务运行总时间/系统运行总时间

中断CPU占用率=中断运行总时间/系统运行总时间

## 开发指导<a name="section11284210152311"></a>

### 接口说明<a name="section3745151592312"></a>

**表 1**  CPUP模块接口

<a name="table147491853163018"></a>
<table><thead align="left"><tr id="row10807205323013"><th class="cellrowborder" valign="top" width="28.3971602839716%" id="mcps1.2.4.1.1"><p id="p980714539304"><a name="p980714539304"></a><a name="p980714539304"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="36.47635236476353%" id="mcps1.2.4.1.2"><p id="p1780715533305"><a name="p1780715533305"></a><a name="p1780715533305"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="35.12648735126487%" id="mcps1.2.4.1.3"><p id="p18807185316301"><a name="p18807185316301"></a><a name="p18807185316301"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row3807145310300"><td class="cellrowborder" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p174011140141013"><a name="p174011140141013"></a><a name="p174011140141013"></a>系统CPU占用率</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p158071153133013"><a name="p158071153133013"></a><a name="p158071153133013"></a>LOS_HistorySysCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p14808115353010"><a name="p14808115353010"></a><a name="p14808115353010"></a>获取系统历史CPU占用率</p>
</td>
</tr>
<tr id="row147461859201016"><td class="cellrowborder" rowspan="2" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p374720596102"><a name="p374720596102"></a><a name="p374720596102"></a>进程CPU占用率</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p3747859101010"><a name="p3747859101010"></a><a name="p3747859101010"></a>LOS_HistoryProcessCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p1747959131016"><a name="p1747959131016"></a><a name="p1747959131016"></a>获取指定进程历史CPU占用率</p>
</td>
</tr>
<tr id="row2075434812116"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17541648171114"><a name="p17541648171114"></a><a name="p17541648171114"></a>LOS_GetAllProcessCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1575419483116"><a name="p1575419483116"></a><a name="p1575419483116"></a>获取系统所有进程的历史CPU占用率</p>
</td>
</tr>
<tr id="row1480855311301"><td class="cellrowborder" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p1618792981018"><a name="p1618792981018"></a><a name="p1618792981018"></a>任务CPU占用率</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p9808185353016"><a name="p9808185353016"></a><a name="p9808185353016"></a>LOS_HistoryTaskCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p12808653183016"><a name="p12808653183016"></a><a name="p12808653183016"></a>获取指定任务历史CPU占用率</p>
</td>
</tr>
<tr id="row680812535306"><td class="cellrowborder" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p13808125314307"><a name="p13808125314307"></a><a name="p13808125314307"></a>中断CPU占用率</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p1480835316303"><a name="p1480835316303"></a><a name="p1480835316303"></a>LOS_GetAllIrqCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p33741531163313"><a name="p33741531163313"></a><a name="p33741531163313"></a>获取系统所有中断的历史CPU占用率</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section122901429182316"></a>

CPU占用率的典型开发流程：

1.  调用获取系统历史CPU占用率函数LOS\_HistorySysCpuUsage。
2.  调用获取指定进程历史CPU占用率函数LOS\_HistoryProcessCpuUsage。
    -   若进程已创建，则关中断，根据不同模式正常获取，恢复中断；
    -   若进程未创建，则返回错误码；

3.  调用获取所有进程CPU占用率函数LOS\_GetAllProcessCpuUsage。
    -   若CPUP已初始化，则关中断，根据不同模式正常获取，恢复中断；
    -   若CPUP未初始化或有非法入参，则返回错误码；

4.  调用获取指定任务历史CPU占用率函数LOS\_HistoryTaskCpuUsage。
    -   若任务已创建，则关中断，根据不同模式正常获取，恢复中断；
    -   若任务未创建，则返回错误码；

5.  调用获取所有中断CPU占用率函数LOS\_GetAllIrqCpuUsage。
    -   若CPUP已初始化，则关中断，根据不同模式正常获取，恢复中断；
    -   若CPUP未初始化或有非法入参，则返回错误码；


### 编程实例<a name="section1765785212310"></a>

本实例实现如下功能：

1.  创建一个用于CPUP测试的任务。
2.  获取当前系统CPUP。
3.  以不同模式获取历史系统CPUP。
4.  获取创建的测试任务的CPUP。
5.  以不同模式获取创建的测试任务的CPUP。

前提条件：

在menuconfig 配置中打开cpup控制开关。

**示例代码**

代码实现如下：

```
#include "los_task.h"
#include "los_cpup.h" 
#define  MODE  4
UINT32 g_cpuTestTaskID;  
VOID ExampleCpup(VOID) 
{      
    printf("entry cpup test example\n");
    while(1) {
        usleep(100);
    }
}
UINT32 ItCpupTest(VOID) 
{     
    UINT32 ret;
    UINT32 cpupUse;
    TSK_INIT_PARAM_S cpupTestTask = { 0 };
    memset(&cpupTestTask, 0, sizeof(TSK_INIT_PARAM_S));
    cpupTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleCpup;
    cpupTestTask.pcName       = "TestCpupTsk"; 
    cpupTestTask.uwStackSize  = 0x800;
    cpupTestTask.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_cpuTestTaskID, &cpupTestTask);
    if(ret != LOS_OK) {
        printf("cpupTestTask create failed .\n");
        return LOS_NOK;
    }

    usleep(100);

    /* 获取当前系统历史cpu占用率 */
    cpupUse = LOS_HistorySysCpuUsage(CPU_LESS_THAN_1S); 
    printf("the history system cpu usage in all time：%u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
    /* 获取指定任务的cpu占用率，该测试例程中指定的任务为以上创建的cpup测试任务 */    
    cpupUse = LOS_HistoryTaskCpuUsage(g_cpuTestTaskID, CPU_LESS_THAN_1S);   
    printf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);   
    return LOS_OK; 
}
```

**结果验证**

编译运行得到的结果为：

```
entry cpup test example
the history system cpu usage in all time: 3.0
cpu usage of the cpupTestTask in all time: TaskID:10 usage: 0.0
```

