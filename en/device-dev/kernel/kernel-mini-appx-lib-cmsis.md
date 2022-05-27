# CMSIS Support

## Basic Concepts

The Cortex Microcontroller Software Interface Standard \([CMSIS](https://developer.arm.com/tools-and-software/embedded/cmsis)\) is a vendor-independent hardware abstraction layer for microcontrollers based on Arm Cortex processors. Of the CMSIS components, the Real Time Operating System \(RTOS\) defines a set of universal and standardized APIs to reduce the dependency of application developers on specific RTOS and facilitate software porting and reuse. The CMSIS provides CMSIS-RTOS v1 and CMSIS-RTOS v2. The OpenHarmony LiteOS-M supports only the implementation of CMSIS-RTOS v2.

## Development Guidelines

### Available APIs

The following table describes CMSIS-RTOS v2 APIs. For more details about the APIs, see the API reference.

**Table  1**  CMSIS-RTOS v2 APIs

| Category| API| Description|
| -------- | -------- | -------- |
| Kernel information and control| osKernelGetInfo | Obtains RTOS kernel information.|
|  | osKernelGetState | Obtains the current RTOS kernel status.|
|  | osKernelGetSysTimerCount | Obtains the RTOS kernel system timer count.|
|  | osKernelGetSysTimerFreq | Obtains the RTOS kernel system timer frequency.|
|  | osKernelInitialize | Initializes the RTOS kernel.|
|  | osKernelLock | Locks the RTOS kernel scheduler.|
|  | osKernelUnlock | Unlocks the RTOS kernel scheduler.|
|  | osKernelRestoreLock | Restores the RTOS kernel scheduler to the locked state.|
|  | osKernelResume | Restores the RTOS kernel scheduler (not implemented yet).|
|  | osKernelStart | Starts the RTOS kernel scheduler.|
|  | osKernelSuspend | Suspends the RTOS kernel scheduler (not implemented yet).|
|  | osKernelGetTickCount | Obtains the RTOS kernel tick count.|
|  | osKernelGetTickFreq | Obtains the RTOS kernel tick frequency.|
| Thread management| osThreadDetach | Detaches a thread (to reclaim the thread storage when the thread terminates).|
|  | osThreadEnumerate | Enumerates active threads (not been implemented yet).|
|  | osThreadExit | Terminates a running thread.|
|  | osThreadGetCount | Obtains the number of active threads.|
|  | osThreadGetId | Obtains the ID of the running thread.|
|  | osThreadGetName | Obtains the thread name.|
|  | osThreadGetPriority | Obtains the current thread priority.|
|  | osThreadGetStackSize | Obtains the thread stack size.|
|  | osThreadGetStackSpace | Obtains the available stack space for a thread based on the stack waterline record during execution.|
|  | osThreadGetState | Obtains the current thread status.|
|  | osThreadJoin | Waits for the specified thread to terminate.|
|  | osThreadNew | Creates a thread and adds it to active threads.|
|  | osThreadResume | Resumes the execution of a thread.|
|  | osThreadSetPriority | Changes the priority of a thread.|
|  | osThreadSuspend | Suspends a thread.|
|  | osThreadTerminate | Terminates a thread.|
|  | osThreadYield | Passes control to the next thread in the ready state.|
| Thread flag| osThreadFlagsSet | Sets flags for a thread.|
|  | osThreadFlagsClear | Clears the specified flags for the running thread.|
|  | osThreadFlagsGet | Obtains the current flags of the running thread.|
|  | osThreadFlagsWait | Waits for one or more thread flags of the running thread to signal.|
| Event flag| osEventFlagsGetName | Obtains the names of the event flags (not implemented yet).|
|  | osEventFlagsNew | Creates and initializes event flags.|
|  | osEventFlagsDelete | Deletes event flags.|
|  | osEventFlagsSet | Sets event flags.|
|  | osEventFlagsClear | Clears event flags.|
|  | osEventFlagsGet | Obtains the current event flags.|
|  | osEventFlagsWait | Waits for one or more event flags to be signaled.|
| General waiting functions| osDelay | Waits for timeout (time delay).|
|  | osDelayUntil | Waits until the specified time.|
| Timer management| osTimerDelete | Deletes a timer.|
|  | osTimerGetName | Obtains the timer name (not implemented yet).|
|  | osTimerIsRunning | Checks whether a timer is running.|
|  | osTimerNew | Creates and initializes a timer.|
|  | osTimerStart | Starts or restarts a timer.|
|  | osTimerStop | Stops a timer.|
| Mutex management| osMutexAcquire | Acquires a mutex or times out (if locked).|
|  | osMutexDelete | Deletes a mutex.|
|  | osMutexGetName | Obtains the mutex name (not implemented yet).|
|  | osMutexGetOwner | Obtains the thread that acquires the mutex.|
|  | osMutexNew | Creates and initializes a mutex.|
|  | osMutexRelease | Releases the mutex obtained using **osMutexAcquire**.|
| Semaphore| osSemaphoreAcquire | Obtains the semaphore token or times out if no token is available.|
|  | osSemaphoreDelete | Deletes a semaphore.|
|  | osSemaphoreGetCount | Obtains the token count of the current semaphore.|
|  | osSemaphoreGetName | Obtains the name of a semaphore (not implemented yet).|
|  | osSemaphoreNew | Creates and initializes a semaphore.|
|  | osSemaphoreRelease | Releases semaphore tokens till the initial maximum count.|
| Memory pool| osMemoryPoolAlloc | Allocates a memory block from the memory pool.|
|  | osMemoryPoolDelete | Deletes a memory pool object.|
|  | osMemoryPoolFree | Releases the allocated memory block to the memory pool.|
|  | osMemoryPoolGetBlockSize | Obtains the memory block size in the memory pool.|
|  | osMemoryPoolGetCapacity | Obtains the maximum number of memory blocks in the memory pool.|
|  | osMemoryPoolGetCount | Obtains the number of used memory blocks in the memory pool.|
|  | osMemoryPoolGetName | Obtains the memory pool name.|
|  | osMemoryPoolGetSpace | Obtains the number of available memory blocks in the memory pool.|
|  | osMemoryPoolNew | Creates and initializes a memory pool.|
| Message queue| osMessageQueueDelete | Deletes a message queue.|
|  | osMessageQueueGet | Obtain a message from the queue or times out if the queue is empty.|
|  | osMessageQueueGetCapacity | Obtains the maximum number of messages in the message queue.|
|  | osMessageQueueGetCount | Obtains the number of queued messages in the message queue.|
|  | osMessageQueueGetMsgSize | Obtains the maximum message size in the memory pool.|
|  | osMessageQueueGetName | Obtains the message queue name (not implemented yet).|
|  | osMessageQueueGetSpace | Obtains the number of slots available for messages in the message queue.|
|  | osMessageQueueNew | Creates and initializes a message queue.|
|  | osMessageQueuePut | Puts the message into the queue or times out if the queue is full.|
|  | osMessageQueueReset | Initialized the message queue to the empty state (not implemented yet).|

### How to Develop

The CMSIS-RTOS v2 component can be provided as a library \(shown in the figure\) or source code. By adding the CMSIS-RTOS v2 component \(typically configuration files\), you can implement RTOS capabilities on CMSIS-based applications. You only need to include the  **cmsis\_os2.h**  header file. RTOS APIs can then be called to process RTOS kernel-related events. You do not need to recompile the source code when the kernel is replaced.

The RTOS object control block definition needs to be called for static object allocation. The implementation-specific header file \(**os\_xx.h**  in the following figure\) provides access to such control block definitions. In the OpenHarmony LiteOS-M kernel, the header files whose names start with  **los\_**  provide the definitions of the kernel.

![](figures/how-to-develop.png)

### Development Example

```
#include ...
#include "cmsis_os2.h"

/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
void app_main (void *argument) {
  // ...
  for (;;) {}
}

int main (void) {
 // Initialize the system.
  MySystemInit();
  // ...

  osKernelInitialize();                // Initialize CMSIS-RTOS.
  osThreadNew(app_main, NULL, NULL);    // Create the main thread of the application.
  osKernelStart();                     // Start to execute the thread.
  for (;;) {}
}
```
