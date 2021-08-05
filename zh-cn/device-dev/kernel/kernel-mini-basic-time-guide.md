# 开发指导<a name="ZH-CN_TOPIC_0000001124066545"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section460018317164)
    -   [实例描述](#section127752801718)
    -   [示例代码](#section321653551711)
    -   [结果验证](#section4366193318167)


用户需要了解当前系统运行的时间以及Tick与秒、毫秒之间的转换关系时，需要使用到时间管理模块的接口。

## 接口说明<a name="section158501652121514"></a>

OpenHarmony LiteOS-M内核的时间管理提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  时间管理接口

<a name="table14277123518139"></a>
<table><thead align="left"><tr id="row152771935131315"><th class="cellrowborder" valign="top" width="17.77177717771777%" id="mcps1.2.4.1.1"><p id="p1127733591316"><a name="p1127733591316"></a><a name="p1127733591316"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="23.782378237823785%" id="mcps1.2.4.1.2"><p id="p22771357138"><a name="p22771357138"></a><a name="p22771357138"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="58.44584458445845%" id="mcps1.2.4.1.3"><p id="p327714358130"><a name="p327714358130"></a><a name="p327714358130"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1627793517136"><td class="cellrowborder" rowspan="4" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p10525141151410"><a name="p10525141151410"></a><a name="p10525141151410"></a>时间转换</p>
</td>
<td class="cellrowborder" valign="top" width="23.782378237823785%" headers="mcps1.2.4.1.2 "><p id="p1027783551315"><a name="p1027783551315"></a><a name="p1027783551315"></a>LOS_MS2Tick</p>
</td>
<td class="cellrowborder" valign="top" width="58.44584458445845%" headers="mcps1.2.4.1.3 "><p id="p1717215119159"><a name="p1717215119159"></a><a name="p1717215119159"></a>毫秒转换成Tick</p>
</td>
</tr>
<tr id="row20278035131316"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p148921018154"><a name="p148921018154"></a><a name="p148921018154"></a>LOS_Tick2MS</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p61721311101517"><a name="p61721311101517"></a><a name="p61721311101517"></a>Tick转化为毫秒</p>
</td>
</tr>
<tr id="row1736713145208"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13367171492014"><a name="p13367171492014"></a><a name="p13367171492014"></a>OsCpuTick2MS</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14367121422016"><a name="p14367121422016"></a><a name="p14367121422016"></a>Cycle数目转化为毫秒，使用2个UINT32类型的数值分别表示结果数值的高、低32位。</p>
</td>
</tr>
<tr id="row19475718122016"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14475121882012"><a name="p14475121882012"></a><a name="p14475121882012"></a>OsCpuTick2US</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p26621730152310"><a name="p26621730152310"></a><a name="p26621730152310"></a>Cycle数目转化为微秒，使用2个UINT32类型的数值分别表示结果数值的高、低32位。</p>
</td>
</tr>
<tr id="row327873511316"><td class="cellrowborder" rowspan="3" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p1743134312156"><a name="p1743134312156"></a><a name="p1743134312156"></a>时间统计</p>
</td>
<td class="cellrowborder" valign="top" width="23.782378237823785%" headers="mcps1.2.4.1.2 "><p id="p18278435131316"><a name="p18278435131316"></a><a name="p18278435131316"></a>LOS_SysClockGet</p>
</td>
<td class="cellrowborder" valign="top" width="58.44584458445845%" headers="mcps1.2.4.1.3 "><p id="p1827813571317"><a name="p1827813571317"></a><a name="p1827813571317"></a>获取系统时钟</p>
</td>
</tr>
<tr id="row1127823541313"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1927810354132"><a name="p1927810354132"></a><a name="p1927810354132"></a>LOS_TickCountGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17278163512131"><a name="p17278163512131"></a><a name="p17278163512131"></a>获取自系统启动以来的Tick数</p>
</td>
</tr>
<tr id="row1027814354131"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1727843510137"><a name="p1727843510137"></a><a name="p1727843510137"></a>LOS_CyclePerTickGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p827819358134"><a name="p827819358134"></a><a name="p827819358134"></a>获取每个Tick多少Cycle数</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

时间管理的典型开发流程：

1.  根据实际需求，完成板级配置适配，并配置系统主时钟频率OS\_SYS\_CLOCK（单位Hz）和LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND。OS\_SYS\_CLOCK的默认值基于硬件平台配置。
2.  调用时钟转换/统计接口。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   时间管理不是单独的功能模块，依赖于OS\_SYS\_CLOCK和LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND两个配置选项。
>-   系统的Tick数在关中断的情况下不进行计数，故系统Tick数不能作为准确时间使用。
>-   配置选项维护在开发板工程的文件target\_config.h。

## 编程实例<a name="section460018317164"></a>

### 实例描述<a name="section127752801718"></a>

在下面的例子中，介绍了时间管理的基本方法，包括：

1.  时间转换：将毫秒数转换为Tick数，或将Tick数转换为毫秒数。
2.  时间统计：每Tick的Cycle数、自系统启动以来的Tick数和延迟后的Tick数。

### 示例代码<a name="section321653551711"></a>

前提条件：

-   使用每秒的Tick数LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND的默认值100。
-   配好OS\_SYS\_CLOCK系统主时钟频率。

时间转换：

```
VOID Example_TransformTime(VOID)
{
    UINT32 ms;
    UINT32 tick;

    tick = LOS_MS2Tick(10000);    // 10000ms转换为tick
    dprintf("tick = %d \n", tick);
    ms = LOS_Tick2MS(100);        // 100tick转换为ms
    dprintf("ms = %d \n", ms);
}
```

时间统计和时间延迟：

```
VOID Example_GetTime(VOID)
{
    UINT32 cyclePerTick;
    UINT64 tickCount;

    cyclePerTick  = LOS_CyclePerTickGet();
    if(0 != cyclePerTick) {
        dprintf("LOS_CyclePerTickGet = %d \n", cyclePerTick);
    }

    tickCount = LOS_TickCountGet();
    if(0 != tickCount) {
        dprintf("LOS_TickCountGet = %d \n", (UINT32)tickCount);
    }

    LOS_TaskDelay(200);
    tickCount = LOS_TickCountGet();
    if(0 != tickCount) {
        dprintf("LOS_TickCountGet after delay = %d \n", (UINT32)tickCount);
    }
}
```

### 结果验证<a name="section4366193318167"></a>

编译运行得到的结果为：

时间转换：

```
tick = 1000
ms = 1000
```

时间统计和时间延迟：

```
LOS_CyclePerTickGet = 495000 
LOS_TickCountGet = 1 
LOS_TickCountGet after delay = 201
```

