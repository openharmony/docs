# Interrupt Management<a name="EN-US_TOPIC_0000001123863135"></a>

-   [Basic Concepts](#section1699312388210)
-   [Available APIs](#section158501652121514)
-   [How to Develop](#section11841123033618)
-   [Development Example](#section460018317164)
-   [Verification](#section668510614519)

## Basic Concepts<a name="section1699312388210"></a>

An interrupt is a signal to the processor emitted by hardware or software indicating an event that needs immediate attention. An interrupt alerts the processor to a high-priority condition requiring the interruption of the current code being executed by the processor. When a hardware interrupt is triggered, the interrupt handler is located based on the interrupt ID and then executed to handle the interrupt.

By using the interrupt mechanism, the CPU responds to the interrupt request from a peripheral only when required, and execute other tasks when the peripherals do not require the CPU. In this way, the CPU does not need to spend a lot of time in waiting and querying the peripheral status, which effectively improves the real-time performance and execution efficiency of the system.

The following describes the concepts related to interrupts:

-   Interrupt ID

    Identifies an interrupt request signal. The computer locates the device that sends the interrupt request based on the interrupt ID.

-   Interrupt request

    A process in which an electrical pulse signal is sent to the CPU, alerting the CPU to a high-priority event requiring the interruption of the current code being executed by the CPU.

-   Interrupt priority

    Prioritizes the sources that trigger interrupts based on the importance and urgency of interrupt events, so that the CPU can respond to and handle all interrupts in a timely manner.

-   Interrupt handler

    A program executed by the CPU to respond to the interrupt request from a peripheral. Each device that triggers an interrupt has its own interrupt handler.

-   Interrupt triggering

    The interrupt source sends an interrupt signal to the interrupt controller. The interrupt controller arbitrates all pending interrupts, determines the priority, and sends the interrupt signal to the CPU. When an interrupt source generates an interrupt signal, the interrupt trigger is set to  **1**, alerting the CPU to respond to the interrupt.

-   Interrupt vector

    Entry address of an interrupt handler.

-   Interrupt vector table

    An area for storing interrupt vectors. It stores the mapping between interrupt vectors and interrupt IDs.


## Available APIs<a name="section158501652121514"></a>

The following table describes APIs available for the OpenHarmony LiteOS-M interrupt module. For more details about the APIs, see the API reference.

**Table  1**  APIs of the interrupt module

<a name="table12470505188"></a>
<table><thead align="left"><tr id="row16470160111812"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p164707031814"><a name="p164707031814"></a><a name="p164707031814"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p15470190151816"><a name="p15470190151816"></a><a name="p15470190151816"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p194701609186"><a name="p194701609186"></a><a name="p194701609186"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14701707188"><td class="cellrowborder" rowspan="2" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p54707061819"><a name="p54707061819"></a><a name="p54707061819"></a>Creating or deleting interrupts</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p5470603184"><a name="p5470603184"></a><a name="p5470603184"></a>HalHwiCreate</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p74706011818"><a name="p74706011818"></a><a name="p74706011818"></a>Creates an interrupt and registers the interrupt ID, interrupt triggering mode, interrupt priority, and interrupt handler. When an interrupt is triggered, the interrupt handler will be called.</p>
</td>
</tr>
<tr id="row154703013184"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p84702002181"><a name="p84702002181"></a><a name="p84702002181"></a>HalHwiDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p114700091815"><a name="p114700091815"></a><a name="p114700091815"></a>Deletes an interrupt based on the specified interrupt ID.</p>
</td>
</tr>
<tr id="row15470506188"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p147010001812"><a name="p147010001812"></a><a name="p147010001812"></a>Enabling or disabling interrupts</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p184701906185"><a name="p184701906185"></a><a name="p184701906185"></a>LOS_IntUnLock</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1847018014188"><a name="p1847018014188"></a><a name="p1847018014188"></a>Enables the CPU to respond to all interrupt requests.</p>
</td>
</tr>
<tr id="row2470902182"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p04711408181"><a name="p04711408181"></a><a name="p04711408181"></a>LOS_IntLock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p194719071819"><a name="p194719071819"></a><a name="p194719071819"></a>Disables the CPU from responding to interrupt requests.</p>
</td>
</tr>
<tr id="row447117051814"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1047112011188"><a name="p1047112011188"></a><a name="p1047112011188"></a>LOS_IntRestore</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1947100121811"><a name="p1947100121811"></a><a name="p1947100121811"></a>Restores the interrupt status before the <strong id="b160497829844357"><a name="b160497829844357"></a><a name="b160497829844357"></a>LOS_IntLock</strong> and <strong id="b123452092644357"><a name="b123452092644357"></a><a name="b123452092644357"></a>LOS_IntUnLock</strong> operations are performed.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section11841123033618"></a>

1.  Create an interrupt by calling  **HalHwiCreate**.
2.  Call  **TestHwiTrigger**  to trigger the specified interrupt. \(This API is defined in the test suite. It simulates an external interrupt by writing the related register of the interrupt controller. Skip this step for common peripheral devices.\)
3.  Call  **HalHwiDelete**  to delete the specified interrupt. Use this API based on actual requirements.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Configure the maximum number of interrupts supported and the number of configurable interrupt priorities based on the specific hardware.
>-   If the interrupt handler takes long time, the CPU cannot respond to interrupt requests in a timely manner.
>-   Functions that trigger  **LOS\_Schedule**  cannot be directly or indirectly executed during interrupt response process.
>-   The input parameter of  **LOS\_IntRestore\(\)**  must be the return value of  **LOS\_IntLock\(\)**, that is, the current program status register \(CPSR\) value before the interrupt is disabled. Interrupts 0 to 15 in the Cortex-M series processors are for internal use. You are advised not to apply for or create interrupts 0 to 15.

## Development Example<a name="section460018317164"></a>

This example implements the following:

1.  Create an interrupt.
2.  Trigger an interrupt.
3.  Delete an interrupt.

The following sample code shows how to create and delete an interrupt. When the interrupt  **HWI\_NUM\_TEST**  is generated, the interrupt handler function will be called.

```
#include "los_interrupt.h"

/* Create an interrupt. */
#define HWI_NUM_TEST 7

STATIC VOID HwiUsrIrq(VOID)
{
    printf("in the func HwiUsrIrq \n"); 
}

static UINT32 Example_Interrupt(VOID)
{
    UINT32 ret;
    HWI_PRIOR_T hwiPrio = 3;
    HWI_MODE_T mode = 0;
    HWI_ARG_T arg = 0;
  
    /* Create an interrupt. */
    ret = HalHwiCreate(HWI_NUM_TEST, hwiPrio, mode, (HWI_PROC_FUNC)HwiUsrIrq, arg);
    if(ret == LOS_OK){
        printf("Hwi create success!\n");
    } else {
        printf("Hwi create failed!\n");
        return LOS_NOK;
    }

    /* Delay 50 ticks. When a hardware interrupt occurs, the HwiUsrIrq function will be called. */
    LOS_TaskDelay(50);

    /* Delete an interrupt. */
    ret = HalHwiDelete(HWI_NUM_TEST);    
    if(ret == LOS_OK){
        printf("Hwi delete success!\n");
    } else {
        printf("Hwi delete failed!\n");
        return LOS_NOK;
    }
    return LOS_OK;
}
```

## Verification<a name="section668510614519"></a>

The development is successful if the return result is as follows:

```
Hwi create success!
Hwi delete success!
```

