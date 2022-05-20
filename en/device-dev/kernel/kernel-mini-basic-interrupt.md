# Interrupt Management

## Basic Concepts

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


## Available APIs

The following table describes APIs available for the OpenHarmony LiteOS-M interrupt module. For more details about the APIs, see the API reference.

**Table  1**  APIs of the interrupt module

| Category| API| Description|
| -------- | -------- | -------- |
| Creating or deleting an interrupt| LOS_HwiCreate | Creates an interrupt and registers the interrupt ID, triggering mode, priority, and interrupt handler. When an interrupt is triggered, the interrupt handler will be called.|
|  | LOS_HwiDelete | Deletes an interrupt based on the specified interrupt ID.|
| Locking or unlocking interrupts| LOS_IntUnLock | Enables the CPU to respond to all interrupt requests.|
|  | LOS_IntLock | Disables the CPU from responding to interrupt requests.|
|  | LOS_IntRestore | Restores the interrupt status before the **LOS_IntLock** and **LOS_IntUnLock** operations are performed.|
| Enabling or disabling an interrupt| LOS_HwiDisable | Disables the CPU from responding to the specified interrupt by setting the register.|
|  | LOS_HwiEnable | Enables the CPU to respond to the specified interrupt by setting the register.|
| Setting the interrupt priority| LOS_HwiSetPriority | Sets the interrupt priority.|
| Triggering an interrupt| LOS_HwiTrigger | Triggers an interrupt (simulate an external interrupt by writing the related register of the interrupt controller).|
| Clearing interrupt register status| LOS_HwiClear | Clears the status bit of the interrupt register corresponding to the interrupt ID. The implementation of this API depends on the interrupt controller version. It is optional.|

## How to Develop

1. Call **LOS_HwiCreate** to create an interrupt.
2. Call **LOS_HwiTrigger** to trigger the interrupt.
3. Call **LOS_HwiDelete** to delete the specified interrupt. Use this API based on actual requirements.

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/>
>-   Configure the maximum number of interrupts supported and the number of configurable interrupt priorities based on the specific hardware.
>-   If the interrupt handler takes long time, the CPU cannot respond to interrupt requests in a timely manner.
>-   Functions that trigger  **LOS\_Schedule**  cannot be directly or indirectly executed during interrupt response process.
>-   The input parameter of  **LOS\_IntRestore\(\)**  must be the return value of  **LOS\_IntLock\(\)**, that is, the current program status register \(CPSR\) value before the interrupt is disabled. Interrupts 0 to 15 in the Cortex-M series processors are for internal use. You are advised not to apply for or create interrupts 0 to 15.

## Development Example

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
    HwiIrqParam irqParam;
    (void)memset_s(&irqParam, sizeof(HwiIrqParam), 0, sizeof(HwiIrqParam));
    irqParam.pDevId = 0;

    /* Create an interrupt. */
    ret = LOS_HwiCreate(HWI_NUM_TEST, hwiPrio, mode, (HWI_PROC_FUNC)HwiUsrIrq, &irqParam);
    if(ret == LOS_OK){
        printf("Hwi create success!\n");
    } else {
        printf("Hwi create failed!\n");
        return LOS_NOK;
    }

    /* Trigger the interrupt. */
    ret = LOS_HwiTrigger(HWI_NUM_TEST);
    if(ret == LOS_OK){
        printf("Hwi trigger success!\n");
    } else {
        printf("Hwi trigger failed!\n");
        return LOS_NOK;
    }

    /* Delete the interrupt. */
    ret = LOS_HwiDelete(HWI_NUM_TEST);    
    if(ret == LOS_OK){
        printf("Hwi delete success!\n");
    } else {
        printf("Hwi delete failed!\n");
        return LOS_NOK;
    }
    return LOS_OK;
}
```

## Verification

The development is successful if the return result is as follows:

```
Hwi create success!
Hwi delete success!
```
