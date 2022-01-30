# Basic Concepts<a name="EN-US_TOPIC_0000001124066587"></a>

Semaphore is a mechanism for implementing inter-task communication. It implements synchronization between tasks or exclusive access to shared resources.

In the data structure of a semaphore, there is a value indicating the number of shared resources available. The value can be:

-   **0**: The semaphore is unavailable. Tasks waiting for the semaphore may exist.
-   Positive number: The semaphore is available.

The semaphore for synchronization is different from the semaphore for mutex:

-   Semaphore used for exclusive access: The initial semaphore counter value is not 0, indicating the number of shared resources available. The semaphore counter value must be acquired before a shared resource is used, and released after the resource is used. When all shared resources are used, the semaphore counter is reduced to 0 and the tasks that need to obtain the semaphores will be blocked. This ensures exclusive access to shared resources. In addition, when the number of shared resources is 1, a binary semaphore \(similar to the mutex mechanism\) is recommended.
-   Semaphore used for synchronization: The initial semaphore counter value is 0. Task 1 cannot acquire the semaphore and is blocked. Task 1 enters Ready or Running state only when the semaphore is released by task 2. In this way, task synchronization is implemented.

## Working Principles<a name="section1794010261861"></a>

### Semaphore control block<a name="section11372149164815"></a>

```
/**
 * Data structure of the semaphore control block
 */
typedef struct {
    UINT16            semStat;          /* Semaphore status */
    UINT16            semType;          /* Semaphore type*/
    UINT16            semCount;         /* Semaphore count*/
    UINT16            semId;            /* Semaphore index*/
    LOS_DL_LIST       semList;          /* Mount the task blocked by the semaphore.*/
} LosSemCB;
```

### Working Principles<a name="section139726510491"></a>

Semaphore initialization: The system allocates memory for the semaphores configured \(you can configure the number of semaphores using the  **LOSCFG\_BASE\_IPC\_SEM\_LIMIT**  macro\), initializes all semaphores to be unused semaphores, and adds them to a linked list for the system to use.

Semaphore creation: The system obtains a semaphore from the linked list of unused semaphores and assigns an initial value to the semaphore.

Semaphore request: If the counter value is greater than 0, the system allocates a semaphore, decreases the value by 1, and returns a success message. Otherwise, the system blocks the task and adds the task to the end of a task queue waiting for semaphores. The wait timeout period can be set.

Semaphore release: When a semaphore is released, if there is no task waiting for it, the counter is increased by 1. Otherwise, the first task in the wait queue is woken up.

Semaphore deletion: The system sets a semaphore in use to unused state and inserts it to the linked list of unused semaphores.

Semaphore allows only a specified number of tasks to access a shared resource at a time. When the number of tasks accessing the resource reaches the limit, other tasks will be blocked until the semaphore is released.

**Figure  1**  Semaphore working mechanism<a name="fig467314634214"></a>  
![](figure/semaphore-working-mechanism.png "semaphore-working-mechanism")

