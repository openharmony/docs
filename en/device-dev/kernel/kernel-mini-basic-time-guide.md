# Development Guidelines<a name="EN-US_TOPIC_0000001124066545"></a>

-   [Available APIs](#section158501652121514)
-   [How to Develop](#section783435801510)
-   [Development Example](#section460018317164)
    -   [Example Description](#section127752801718)
    -   [Sample Code](#section321653551711)
    -   [Verification](#section4366193318167)


The time management module provides APIs to implement conversion between the system running time, ticks, and seconds/milliseconds.

## Available APIs<a name="section158501652121514"></a>

The following table describes APIs available for the OpenHarmony LiteOS-M time management. For more details about the APIs, see the API reference.

**Table  1**  APIs of the time management module

<a name="table14277123518139"></a>
<table><thead align="left"><tr id="row152771935131315"><th class="cellrowborder" valign="top" width="17.77177717771777%" id="mcps1.2.4.1.1"><p id="p1127733591316"><a name="p1127733591316"></a><a name="p1127733591316"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="23.782378237823785%" id="mcps1.2.4.1.2"><p id="p22771357138"><a name="p22771357138"></a><a name="p22771357138"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="58.44584458445845%" id="mcps1.2.4.1.3"><p id="p327714358130"><a name="p327714358130"></a><a name="p327714358130"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1627793517136"><td class="cellrowborder" rowspan="4" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p10525141151410"><a name="p10525141151410"></a><a name="p10525141151410"></a>Time conversion</p>
</td>
<td class="cellrowborder" valign="top" width="23.782378237823785%" headers="mcps1.2.4.1.2 "><p id="p1027783551315"><a name="p1027783551315"></a><a name="p1027783551315"></a>LOS_MS2Tick</p>
</td>
<td class="cellrowborder" valign="top" width="58.44584458445845%" headers="mcps1.2.4.1.3 "><p id="p1717215119159"><a name="p1717215119159"></a><a name="p1717215119159"></a>Converts milliseconds into ticks.</p>
</td>
</tr>
<tr id="row20278035131316"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p148921018154"><a name="p148921018154"></a><a name="p148921018154"></a>LOS_Tick2MS</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p61721311101517"><a name="p61721311101517"></a><a name="p61721311101517"></a>Converts ticks into milliseconds.</p>
</td>
</tr>
<tr id="row1736713145208"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13367171492014"><a name="p13367171492014"></a><a name="p13367171492014"></a>OsCpuTick2MS</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14367121422016"><a name="p14367121422016"></a><a name="p14367121422016"></a>Converts cycles into milliseconds. Two UINT32 values indicate the high-order and low-order 32 bits of the result value, respectively.</p>
</td>
</tr>
<tr id="row19475718122016"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14475121882012"><a name="p14475121882012"></a><a name="p14475121882012"></a>OsCpuTick2US</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p26621730152310"><a name="p26621730152310"></a><a name="p26621730152310"></a>Converts cycles into microseconds. Two UINT32 values indicate the high-order and low-order 32 bits of the result value, respectively.</p>
</td>
</tr>
<tr id="row327873511316"><td class="cellrowborder" rowspan="3" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p1743134312156"><a name="p1743134312156"></a><a name="p1743134312156"></a>Time statistics</p>
</td>
<td class="cellrowborder" valign="top" width="23.782378237823785%" headers="mcps1.2.4.1.2 "><p id="p18278435131316"><a name="p18278435131316"></a><a name="p18278435131316"></a>LOS_SysClockGet</p>
</td>
<td class="cellrowborder" valign="top" width="58.44584458445845%" headers="mcps1.2.4.1.3 "><p id="p1827813571317"><a name="p1827813571317"></a><a name="p1827813571317"></a>Obtains the system clock.</p>
</td>
</tr>
<tr id="row1127823541313"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1927810354132"><a name="p1927810354132"></a><a name="p1927810354132"></a>LOS_TickCountGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17278163512131"><a name="p17278163512131"></a><a name="p17278163512131"></a>Obtains the number of ticks since the system starts.</p>
</td>
</tr>
<tr id="row1027814354131"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1727843510137"><a name="p1727843510137"></a><a name="p1727843510137"></a>LOS_CyclePerTickGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p827819358134"><a name="p827819358134"></a><a name="p827819358134"></a>Obtains the number of cycles for each tick.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section783435801510"></a>

The typical development process of time management is as follows:

1.  Complete board configuration and adaptation as required, and configure the system clock frequency \(**OS\_SYS\_CLOCK**  in Hz and  **LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND**\). The default value of  **OS\_SYS\_CLOCK**  varies with the hardware platform.
2.  Call the clock conversion and statistics APIs.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The time management module depends on  **OS\_SYS\_CLOCK**  and  **LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND**.
>-   The number of system ticks is not counted when the interrupt feature is disabled. Therefore, the number of ticks cannot be used as the accurate time.
>-   The configuration options are maintained in the  **target\_config.h**  file of the development board project.

## Development Example<a name="section460018317164"></a>

### Example Description<a name="section127752801718"></a>

The following example describes basic time management methods, including:

1.  Time conversion: converts milliseconds to ticks or converts ticks to milliseconds.
2.  Time statistics: obtains the number of cycles per tick, number of ticks since system startup, and number of delayed ticks.

### Sample Code<a name="section321653551711"></a>

Prerequisites

-   The default value of  **LOSCFG\_BASE\_CORE\_TICK\_PER\_SECOND**  is  **100**.
-   The system clock frequency  **OS\_SYS\_CLOCK**  is configured.

Time conversion:

```
VOID Example_TransformTime(VOID)
{
    UINT32 ms;
    UINT32 tick;

    tick = LOS_MS2Tick(10000);    // Convert 10000 ms into ticks.
    dprintf("tick = %d \n", tick);
    ms = LOS_Tick2MS(100);        // Convert 100 ticks into ms.
    dprintf("ms = %d \n", ms);
}
```

Time statistics and delay:

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

### Verification<a name="section4366193318167"></a>

The development is successful if the return result is as follows:

Time conversion:

```
tick = 1000
ms = 1000
```

Time statistics and delay:

```
LOS_CyclePerTickGet = 495000 
LOS_TickCountGet = 1 
LOS_TickCountGet after delay = 201
```

