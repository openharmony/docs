# Interrupt and Exception Handling


## Basic Concepts<a name="section439816296117"></a>

An interrupt is a signal to the processor emitted by hardware or software indicating an event that needs immediate attention. An interrupt alerts the processor of a high-priority condition requiring interruption of the code being executed by the processor. In this way, the CPU does not need to spend a lot of time in waiting and querying the peripheral status, which effectively improves the real-time performance and execution efficiency of the system.

Exception handling involves a series of actions taken by the OS to respond to exceptions \(chip hardware faults\) that occurred during the OS running, for example, printing the call stack information of the current function, CPU information, and call stack information of tasks when the virtual memory page is missing.

## Working Principles<a name="section2792838318"></a>

Peripherals can complete certain work without the intervention of the CPU. In some cases, however, the CPU needs to perform certain work for peripherals. With the interrupt mechanism, the CPU responds to the interrupt request from a peripheral only when required, and execute other tasks when the peripherals do not require the CPU. The interrupt controller receives the input of other peripheral interrupt pins and sends interrupt signals to the CPU. You can enable or disable the interrupt source and set the priority and trigger mode of the interrupt source by programming the interrupt controller. Common interrupt controllers include vector interrupt controllers \(VICs\) and general interrupt controllers \(GICs\). The ARM Cortex-A7 uses GICs. After receiving an interrupt signal sent by the interrupt controller, the CPU interrupts the current task to respond to the interrupt request.

Exception handling interrupts the normal running process of the CPU to handle exceptions, such as, undefined instructions, an attempt to modify read-only data, and unaligned address access. When an exception occurs, the CPU suspends the current program, handles the exception, and then continues to execute the program interrupted by the exception.

The following uses the ARMv7-a architecture as an example. The interrupt vector table is the entry for interrupt and exception handling. The interrupt vector table contains the entry function for each interrupt and exception handling.

**Figure  1**  Interrupt vector table<a name="fig1552753243714"></a>  
![](figures/interrupt-vector-table.png "interrupt-vector-table")

## Development Guidelines<a name="section15415165510110"></a>

### Available APIs<a name="section57441612024"></a>

Exception handling is an internal mechanism and does not provide external APIs. The following table describes APIs available for the interrupt module.

<a name="table11657113333110"></a>
<table><thead align="left"><tr id="row1170612337312"><th class="cellrowborder" valign="top" width="19.900000000000002%" id="mcps1.1.4.1.1"><p id="p4706133373112"><a name="p4706133373112"></a><a name="p4706133373112"></a><strong id="b7792162213202"><a name="b7792162213202"></a><a name="b7792162213202"></a>Function</strong></p>
</th>
<th class="cellrowborder" valign="top" width="18.43%" id="mcps1.1.4.1.2"><p id="p1070653343117"><a name="p1070653343117"></a><a name="p1070653343117"></a><strong id="b19958356201"><a name="b19958356201"></a><a name="b19958356201"></a>API</strong></p>
</th>
<th class="cellrowborder" valign="top" width="61.67%" id="mcps1.1.4.1.3"><p id="p370613330311"><a name="p370613330311"></a><a name="p370613330311"></a><strong id="b1551072610204"><a name="b1551072610204"></a><a name="b1551072610204"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row8706123317311"><td class="cellrowborder" rowspan="2" valign="top" width="19.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p4706193319318"><a name="p4706193319318"></a><a name="p4706193319318"></a>Creating or deleting interrupts</p>
</td>
<td class="cellrowborder" valign="top" width="18.43%" headers="mcps1.1.4.1.2 "><p id="p170683310317"><a name="p170683310317"></a><a name="p170683310317"></a>LOS_HwiCreate</p>
</td>
<td class="cellrowborder" valign="top" width="61.67%" headers="mcps1.1.4.1.3 "><p id="p15706833163110"><a name="p15706833163110"></a><a name="p15706833163110"></a>Creates an interrupt and registers the interrupt ID, interrupt triggering mode, interrupt priority, and interrupt handler. When an interrupt is triggered, the interrupt handler will be called.</p>
</td>
</tr>
<tr id="row18706153318316"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p1870615332312"><a name="p1870615332312"></a><a name="p1870615332312"></a>LOS_HwiDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p770616333313"><a name="p770616333313"></a><a name="p770616333313"></a>Deletes an interrupt.</p>
</td>
</tr>
<tr id="row1370633316316"><td class="cellrowborder" rowspan="3" valign="top" width="19.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p970611333318"><a name="p970611333318"></a><a name="p970611333318"></a>Enabling and disabling all interrupts</p>
</td>
<td class="cellrowborder" valign="top" width="18.43%" headers="mcps1.1.4.1.2 "><p id="p147061033103117"><a name="p147061033103117"></a><a name="p147061033103117"></a>LOS_IntUnLock</p>
</td>
<td class="cellrowborder" valign="top" width="61.67%" headers="mcps1.1.4.1.3 "><p id="p93681327171713"><a name="p93681327171713"></a><a name="p93681327171713"></a>Enables all interrupts of the current processor.</p>
</td>
</tr>
<tr id="row1270603314312"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p1970623343114"><a name="p1970623343114"></a><a name="p1970623343114"></a>LOS_IntLock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1161283971712"><a name="p1161283971712"></a><a name="p1161283971712"></a>Disables all interrupts for the current processor.</p>
</td>
</tr>
<tr id="row8706233173113"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p1770620337313"><a name="p1770620337313"></a><a name="p1770620337313"></a>LOS_IntRestore</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1470643323112"><a name="p1470643323112"></a><a name="p1470643323112"></a>Restores to the status before all interrupts are disabled by using <strong id="b354311504226"><a name="b354311504226"></a><a name="b354311504226"></a>LOS_IntLock</strong>.</p>
</td>
</tr>
<tr id="row870793320317"><td class="cellrowborder" valign="top" width="19.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1970763318316"><a name="p1970763318316"></a><a name="p1970763318316"></a>Obtaining the maximum number of interrupts supported</p>
</td>
<td class="cellrowborder" valign="top" width="18.43%" headers="mcps1.1.4.1.2 "><p id="p1707333123115"><a name="p1707333123115"></a><a name="p1707333123115"></a>LOS_GetSystemHwiMaximum</p>
</td>
<td class="cellrowborder" valign="top" width="61.67%" headers="mcps1.1.4.1.3 "><p id="p4707173323111"><a name="p4707173323111"></a><a name="p4707173323111"></a>Obtains the maximum number of interrupts supported by the system.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section64332181221"></a>

1.  Call  **LOS\_HwiCreate**  to create an interrupt.
2.  Call  **LOS\_HwiDelete**  to delete the specified interrupt. Use this API based on actual requirements.

### Development Example<a name="section204698276478"></a>

This example implements the following:

1.  Create an interrupt.
2.  Delete an interrupt.

The following sample code shows how to create and delete an interrupt. When the interrupt  **HWI\_NUM\_TEST**  is generated, the interrupt handler function will be called.

```
#include "los_hwi.h"
/* Interrupt handler function*/
STATIC VOID HwiUsrIrq(VOID)
{
    printf("in the func HwiUsrIrq \n"); 
}

static UINT32 Example_Interrupt(VOID)
{
    UINT32 ret;
    HWI_HANDLE_T hwiNum = 7;
    HWI_PRIOR_T hwiPrio = 3;
    HWI_MODE_T mode = 0;
    HWI_ARG_T arg = 0;

/* Create an interrupt.*/
    ret = LOS_HwiCreate(hwiNum, hwiPrio, mode, (HWI_PROC_FUNC)HwiUsrIrq, (HwiIrqParam *)arg);
    if(ret == LOS_OK){
        printf("Hwi create success!\n");
    } else {
        printf("Hwi create failed!\n");
        return LOS_NOK;
    }

    /* Delay 50 ticks. When a hardware interrupt occurs, call the HwiUsrIrq function.*/
    LOS_TaskDelay(50);

    /* Delete an interrupt./
    ret = LOS_HwiDelete(hwiNum, (HwiIrqParam *)arg);    
    if(ret == LOS_OK){
        printf("Hwi delete success!\n");
    } else {
        printf("Hwi delete failed!\n");
        return LOS_NOK;
    }
    return LOS_OK;
}
```

### Verification<a name="section1466144215476"></a>

The development is successful if the return result is as follows:

```
Hwi create success!
Hwi delete success!
```

