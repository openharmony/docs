# 开发指导<a name="ZH-CN_TOPIC_0000001079036450"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section460018317164)
    -   [实例描述](#section51413507517)
    -   [示例代码](#section17617965523)
    -   [结果验证](#section1968771515188)


## 接口说明<a name="section158501652121514"></a>

**表 1**  功能列表

<a name="table18293928155615"></a>
<table><thead align="left"><tr id="row129362875613"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p19444103765618"><a name="p19444103765618"></a><a name="p19444103765618"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p944473716569"><a name="p944473716569"></a><a name="p944473716569"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p144445378565"><a name="p144445378565"></a><a name="p144445378565"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1143613475615"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p942993405610"><a name="p942993405610"></a><a name="p942993405610"></a>获取系统CPU占用率</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p242973419563"><a name="p242973419563"></a><a name="p242973419563"></a>LOS_SysCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7429163416565"><a name="p7429163416565"></a><a name="p7429163416565"></a>获取当前系统CPU占用率</p>
</td>
</tr>
<tr id="row15436163435611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20429183410563"><a name="p20429183410563"></a><a name="p20429183410563"></a>LOS_HistorySysCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p542953465617"><a name="p542953465617"></a><a name="p542953465617"></a>获取系统历史CPU占用率</p>
</td>
</tr>
<tr id="row143610342562"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p174295347568"><a name="p174295347568"></a><a name="p174295347568"></a>获取任务CPU占用率</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p124291734155614"><a name="p124291734155614"></a><a name="p124291734155614"></a>LOS_TaskCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1042963410568"><a name="p1042963410568"></a><a name="p1042963410568"></a>获取指定任务CPU占用率</p>
</td>
</tr>
<tr id="row12436143414561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6429834185613"><a name="p6429834185613"></a><a name="p6429834185613"></a>LOS_HistoryTaskCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p74302034175614"><a name="p74302034175614"></a><a name="p74302034175614"></a>获取指定任务历史CPU占用率</p>
</td>
</tr>
<tr id="row2435834135618"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p843073420563"><a name="p843073420563"></a><a name="p843073420563"></a>LOS_AllCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4430134185614"><a name="p4430134185614"></a><a name="p4430134185614"></a>获取所有任务CPU占用率</p>
</td>
</tr>
<tr id="row15435934155618"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1543033435615"><a name="p1543033435615"></a><a name="p1543033435615"></a>输出任务CPU占用率</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1643016342562"><a name="p1643016342562"></a><a name="p1643016342562"></a>LOS_CpupUsageMonitor</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p84301234115617"><a name="p84301234115617"></a><a name="p84301234115617"></a>输出任务历史CPU占用率</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

CPU占用率的典型开发流程：

1.  调用获取系统CPU使用率函数LOS\_SysCpuUsage。
2.  调用获取系统历史CPU使用率函数LOS\_HistorySysCpuUsage。
3.  调用获取指定任务CPU使用率函数LOS\_TaskCpuUsage。
    -   若任务已创建，则关中断，正常获取，恢复中断；
    -   若任务未创建，则返回错误码；

4.  调用获取指定任务历史CPU使用率函数LOS\_HistoryTaskCpuUsage。
    -   若任务已创建，则关中断，根据不同模式正常获取，恢复中断；
    -   若任务未创建，则返回错误码；

5.  调用获取所有任务CPU使用率函数LOS\_AllCpuUsage。
    -   若CPUP已初始化，则关中断，根据不同模式正常获取，恢复中断；
    -   若CPUP未初始化或有非法入参，则返回错误码；


## 编程实例<a name="section460018317164"></a>

### 实例描述<a name="section51413507517"></a>

本实例实现如下功能：

1.  创建一个用于CPUP测试的任务。
2.  获取当前系统CPUP。
3.  以不同模式获取历史系统CPUP。
4.  获取创建的测试任务的CPUP。
5.  以不同模式获取创建的测试任务的CPUP

### 示例代码<a name="section17617965523"></a>

前提条件：

在target\_config.h中将LOSCFG\_BASE\_CORE\_CPUP配置项打开。

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

    /* 获取当前系统cpu占用率 */
    cpupUse = LOS_SysCpuUsage();
    printf("the current system cpu usage is: %u.%u\n",
            cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT); 

    cpupUse = LOS_HistorySysCpuUsage(CPU_LESS_THAN_1S);
    /* 获取指定任务的cpu占用率，该测试例程中指定的任务为以上创建的cpup测试任务 */    
    printf("the history system cpu usage in all time：%u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
    cpupUse = LOS_TaskCpuUsage(g_cpuTestTaskID);    
    /* 获取指定历史任务在系统启动到现在的cpu占用率，该测试例程中指定的任务为以上创建的cpup测试任务 */    
    printf("cpu usage of the cpupTestTask:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT); 
    cpupUse = LOS_HistoryTaskCpuUsage(g_cpuTestTaskID, CPU_LESS_THAN_1S);   
    printf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);   
    return LOS_OK; 
}
```

### 结果验证<a name="section1968771515188"></a>

编译运行得到的结果为：

```
entry cpup test example 
the current system cpu usage is : 1.5
 the history system cpu usage in all time: 3.0
 cpu usage of the cpupTestTask: TaskID:10 usage: 0.0
 cpu usage of the cpupTestTask&nbsp;in all time: TaskID:10 usage: 0.0
```

