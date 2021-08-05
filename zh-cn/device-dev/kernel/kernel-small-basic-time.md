# 时间管理<a name="ZH-CN_TOPIC_0000001123753363"></a>

-   [基本概念](#section12903185785119)
-   [开发指导](#section430981720522)
    -   [接口说明](#section1040142705214)
    -   [开发流程](#section1381224710522)
    -   [编程实例](#section1344610245416)


## 基本概念<a name="section12903185785119"></a>

时间管理以系统时钟为基础。时间管理提供给应用程序所有和时间有关的服务。系统时钟是由定时/计数器产生的输出脉冲触发中断而产生的，一般定义为整数或长整数。输出脉冲的周期叫做一个“时钟滴答”。系统时钟也称为时标或者Tick。一个Tick的时长可以静态配置。用户是以秒、毫秒为单位计时，而操作系统时钟计时是以Tick为单位的，当用户需要对系统操作时，例如任务挂起、延时等，输入秒为单位的数值，此时需要时间管理模块对二者进行转换。

Tick与秒之间的对应关系可以配置。

-   **Cycle**

    系统最小的计时单位。Cycle的时长由系统主频决定，系统主频就是每秒钟的Cycle数。


-   **Tick**

    Tick是操作系统的基本时间单位，对应的时长由系统主频及每秒Tick数决定，由用户配置。


OpenHarmony系统的时间管理模块提供时间转换、统计、延迟功能以满足用户对时间相关需求的实现。

## 开发指导<a name="section430981720522"></a>

用户需要了解当前系统运行的时间以及Tick与秒、毫秒之间的转换关系时，需要使用到时间管理模块的接口。

### 接口说明<a name="section1040142705214"></a>

OpenHarmony LiteOS-A内核的时间管理提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  时间管理相关接口说明

<a name="table1316220185211"></a>
<table><thead align="left"><tr id="row191622182021"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p13162121815218"><a name="p13162121815218"></a><a name="p13162121815218"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p12162618623"><a name="p12162618623"></a><a name="p12162618623"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p16162118427"><a name="p16162118427"></a><a name="p16162118427"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row04981218910"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p6462616696"><a name="p6462616696"></a><a name="p6462616696"></a>时间转换</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p164931214913"><a name="p164931214913"></a><a name="p164931214913"></a>LOS_MS2Tick</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p8504121996"><a name="p8504121996"></a><a name="p8504121996"></a>毫秒转换成Tick</p>
</td>
</tr>
<tr id="row7162101814216"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p816311185217"><a name="p816311185217"></a><a name="p816311185217"></a>LOS_Tick2MS</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p161632181721"><a name="p161632181721"></a><a name="p161632181721"></a>Tick转换成毫秒</p>
</td>
</tr>
<tr id="row1516317181227"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1077619231696"><a name="p1077619231696"></a><a name="p1077619231696"></a>时间统计</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p181638181921"><a name="p181638181921"></a><a name="p181638181921"></a>LOS_TickCountGet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p615864811116"><a name="p615864811116"></a><a name="p615864811116"></a>获取当前Tick数</p>
</td>
</tr>
<tr id="row101631818620"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p71633181125"><a name="p71633181125"></a><a name="p71633181125"></a>LOS_CyclePerTickGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p151631718124"><a name="p151631718124"></a><a name="p151631718124"></a>每个Tick的cycle数</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section1381224710522"></a>

1.  调用时间转换接口；
2.  获取系统Tick数完成时间统计等。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   获取系统Tick数需要在系统时钟使能之后。
>-   时间管理不是单独的功能模块，依赖于los\_config.h中的OS\_SYS\_CLOCK和LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND两个配置选项。
>-   系统的Tick数在关中断的情况下不进行计数，故系统Tick数不能作为准确时间计算。

### 编程实例<a name="section1344610245416"></a>

前置条件：

-   配置好LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND，即系统每秒的Tick数。
-   配置好OS\_SYS\_CLOCK 系统时钟频率，单位：Hz。

**示例代码**

时间转换：

```
VOID Example_TransformTime(VOID)
{
    UINT32 uwMs;
    UINT32 uwTick;
    uwTick = LOS_MS2Tick(10000); //10000 ms数转换为Tick数
    PRINTK("uwTick = %d \n",uwTick);
    uwMs= LOS_Tick2MS(100); //100 Tick数转换为ms数
    PRINTK("uwMs = %d \n",uwMs);
}
```

时间统计和时间延迟：

```
VOID Example_GetTime(VOID)
{
    UINT32 uwcyclePerTick;
    UINT64 uwTickCount;

    uwcyclePerTick = LOS_CyclePerTickGet(); //每个Tick多少Cycle数
    if(0 != uwcyclePerTick)
    {
        PRINTK("LOS_CyclePerTickGet = %d \n", uwcyclePerTick);
    }

    uwTickCount = LOS_TickCountGet(); //获取Tick数
    if(0 != uwTickCount)
    {
        PRINTK("LOS_TickCountGet = %d \n", (UINT32)uwTickCount);
    }
    LOS_TaskDelay(200);//延迟200 Tick
    uwTickCount = LOS_TickCountGet();
    if(0 != uwTickCount)
    {
        PRINTK("LOS_TickCountGet after delay = %d \n", (UINT32)uwTickCount);
    }
}
```

**结果验证**

编译运行的结果如下：

时间转换：

```
uwTick = 10000 
uwMs = 100
```

时间统计和时间延迟：

```
LOS_CyclePerTickGet = 49500 
LOS_TickCountGet = 5042
LOS_TickCountGet after delay = 5242
```

