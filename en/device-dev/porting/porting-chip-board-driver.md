# Board-Level Driver Adaptation<a name="EN-US_TOPIC_0000001153683028"></a>

To implement board-level driver adaptation, perform the following steps:

1.  Develop the SDK based on the CMSIS/POSIX APIs provided by OpenHarmony.

    The board-level SDK can be adapted to OS interfaces via CMSIS and POSIX APIs. Currently, the LiteOS Cortex-M kernel is adapted to most CMSIS APIs \(including APIs used for basic kernel management, thread management, timer, event, mutex, semaphore, and queue\), which meets the requirements of porting. POSIX APIs provide basic capabilities for porting, and more POSIX APIs are to be implemented. If the SDK is implemented based on the CMSIS or POSIX APIs, it can directly adapt to the LiteOS Cortex-M kernel.

    If the SDK is developed based on other embedded OSs such as FreeRTOS, or has an abstraction layer for OS interfaces, it is recommended that the OS-dependent APIs be directly adapted to the CMSIS APIs.

    Here is an OS interface defined by a product for creating a queue:

    ```
    bool osif_msg_queue_create(void **pp_handle, uint32_t msg_num, uint32_t msg_size)
    ```

    The CMSIS API used for creating a queue is as follows:

    ```
    osMessageQueueId_t osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osMessageQueueAttr_t *attr);
    ```

    The following example shows how to adapt the OS interface to the CMSIS API:

    ```
    #include "CMSIS_os2.h"
    osMessageQueueId_t osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osMessageQueueAttr_t *attr);
    bool osif_msg_queue_create(void **pp_handle, uint32_t msg_num, uint32_t msg_size)
    {
    	(*pp_handle) = osMessageQueueNew (msg_num, msg_size, NULL);
    	if((*pp_handle) == NULL){
    		return FALSE;
    	}
    	return TRUE;
    }
    ```

2.  Compile the SDK independently or modify the SDK based on the OpenHarmony building framework and integrate the SDK code into the  **device**  directory of OpenHarmony as required.

    After completing the OS API adaptation, you can integrate the board-level driver to OpenHarmony by the following two methods:

    -   Compile the SDK independently and link it to the OpenHarmony project in the binary format.
    -   Modify the SDK building framework based on OpenHarmony. Considering the long-term evolution and subsequent joint debugging, you are advised to compile the SDK based on the GN building framework and link it to the OpenHarmony project in the form of source code.

3.  Verify the basic functions of the SDK.

