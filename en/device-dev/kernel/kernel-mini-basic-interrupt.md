# Interrupt Management


## Basic Concepts

An interrupt is a signal to the processor emitted by hardware or software indicating an event that needs immediate attention. An interrupt alerts the processor to a high-priority condition requiring the interruption of the current code being executed by the processor. When a hardware interrupt is triggered, the interrupt handler is located based on the interrupt ID and then executed to handle the interrupt.

By using the interrupt mechanism, the CPU responds to the interrupt request (IRQ) from a peripheral only when required, and execute other tasks when the peripherals do not require the CPU. In this way, the CPU does not need to spend a lot of time in waiting and querying the peripheral status, which effectively improves the real-time performance and execution efficiency of the system.

To understand interrupts, you need to know the following concepts:

- Interrupt ID
  
  Identifies an IRQ signal. The computer locates the device that sends the IRQ based on the interrupt ID.
- IRQ
  
  An electrical pulse signal sent to the CPU, alerting the CPU to a high-priority event requiring the interruption of the current code being executed by the CPU.
- Interrupt priority
  
  Prioritizes the sources that trigger interrupts based on the importance and urgency of interrupt events, so that the CPU can respond to and handle all interrupts in a timely manner.
- Interrupt handler
  
  A program executed by the CPU to respond to the IRQ from a peripheral. Each device that triggers an interrupt has its own interrupt handler.
- Interrupt triggering
  
  The interrupt source sends an interrupt signal to the interrupt controller. The interrupt controller arbitrates all pending interrupts, determines the priority, and sends the interrupt signal to the CPU. When an interrupt source generates an interrupt signal, the interrupt trigger is set to **1**, alerting the CPU to respond to the interrupt.
- Interrupt vector
  
  Entry address of an interrupt handler.
- Interrupt vector table
  
  An area for storing interrupt vectors. It stores the mapping between interrupt vectors and interrupt IDs.


## Available APIs

The following table describes APIs available for the OpenHarmony LiteOS-M interrupt module. For more details about the APIs, see the API reference.

  **Table 1** APIs for creating and deleting an interrupt

| API| Description|
| -------- | -------- |
| LOS_HwiCreate | Creates an interrupt and registers the interrupt ID, triggering mode, priority, and interrupt handler. When an interrupt is triggered, the interrupt handler will be called.|
| LOS_HwiDelete | Deletes an interrupt based on the specified interrupt ID.|

  **Table 2** APIs for enabling and disabling interrupts

| API| Description|
| -------- | -------- |
| LOS_IntUnLock | Enables the CPU to respond to all IRQs.|
| LOS_IntLock | Disables the CPU from responding to IRQs.|
| LOS_IntRestore | Restores the interrupt status before the **LOS_IntLock** and **LOS_IntUnLock** operations are performed.|

  **Table 3** APIs for other interrupt operations

| API            | Description            |
| :----------------- | ---------------- |
| LOS_HwiTrigger     | Triggers an interrupt.      |
| LOS_HwiEnable      | Enables interrupts.      |
| LOS_HwiDisable     | Disables interrupts.      |
| LOS_HwiClear       | Clears an interrupt manually.  |
| LOS_HwiSetPriority | Sets the interrupt priority.|
| LOS_HwiCurIrqNum   | Obtains the current interrupt ID.|


## How to Develop

1. Call **LOS_HwiCreate** to create an interrupt.

2. Call **LOS_HwiTrigger()** to trigger an interrupt (write the related register of the interrupt controller to simulate an external interrupt) or trigger an interrupt by using a peripheral.

3. Call **LOS_HwiDelete()** to delete an interrupt. Use this API based on actual requirements.


> **NOTE**
> - Set the maximum number of interrupts supported and the number of configurable interrupt priorities based on the hardware.
> - Avoid long interrupt disabling time or interrupt handler processing time. Otherwise, the CPU cannot respond to interrupts in a timely manner.
> - Do not directly or indirectly call the API that causes scheduling, such as **LOS_Schedule**, during the interrupt response process.
> - The input parameter of **LOS_IntRestore()** must be the return value of **LOS_IntLock()**, that is, the current program status register (CPSR) value before the interrupt is disabled.
> - Interrupts 0 to 15 are for internal use of the Cortex-M series processors. You are advised not to apply for or create interrupts 0 to 15.


## Development Example

This example implements the following:

1. Create an interrupt.

2. Trigger an interrupt.

3. Delete an interrupt.

The following sample code demonstrates how to create an interrupt, trigger the interrupt to invoke the interrupt handler, and delete the interrupt.

The sample code is compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. Call **ExampleInterrupt()** in **TestTaskEntry**.


```
#include "los_interrupt.h"
#include "los_compiler.h"

/* Interrupt ID to verify */
#define HWI_NUM_TEST 7

/* Interrupt handler */
STATIC VOID UsrIrqEntry(VOID)
{
    printf("in the func UsrIrqEntry\n");
}

/* Register a thread callback to trigger the interrupt */
STATIC VOID InterruptTest(VOID)
{
    LOS_HwiTrigger(HWI_NUM_TEST);
}

UINT32 ExampleInterrupt(VOID)
{
    UINT32 ret;
    HWI_PRIOR_T hwiPrio = 3; // Interrupt priority
    HWI_MODE_T mode = 0;
    HWI_ARG_T arg = 0;

    /* Create an interrupt. */
    ret = LOS_HwiCreate(HWI_NUM_TEST, hwiPrio, mode, (HWI_PROC_FUNC)UsrIrqEntry, arg);
    if(ret == LOS_OK){
        printf("Hwi create success!\n");
    } else {
        printf("Hwi create failed!\n");
        return LOS_NOK;
    }

    TSK_INIT_PARAM_S taskParam = { 0 };
    UINT32 testTaskID;
	
	/* Create a thread with a low priority to verify interrupt triggering.*/
    taskParam.pfnTaskEntry = (TSK_ENTRY_FUNC)InterruptTest;
    taskParam.uwStackSize = OS_TSK_TEST_STACK_SIZE;
    taskParam.pcName = "InterruptTest";
    taskParam.usTaskPrio = TASK_PRIO_TEST - 1;
    taskParam.uwResved = LOS_TASK_ATTR_JOINABLE;
    ret = LOS_TaskCreate(&testTaskID, &taskParam);
    if (LOS_OK != ret) {
        PRINTF("InterruptTest task error\n");
    }

    /* Delay 50 ticks to release the scheduling of the current thread. */
    LOS_TaskDelay(50);

    /* Delete the registered interrupt. */
    ret = LOS_HwiDelete(HWI_NUM_TEST, NULL);
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
in the func UsrIrqEntry
Hwi delete success!
```

