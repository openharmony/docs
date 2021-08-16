# Basic Concepts<a name="EN-US_TOPIC_0000001078716896"></a>

-   [Working Principles](#section115161649726)

A mutual exclusion \(mutex\) is a special binary semaphore used for exclusive access to shared resources.

A mutex can be unlocked or locked. When a mutex is held by a task, the mutex is locked and the task obtains the ownership of the mutex. When the task releases the mutex, the mutex is unlocked and the task will lose the ownership of the mutex. When a task holds a mutex, other tasks cannot unlock or hold the mutex.

In an environment where multiple tasks compete for shared resources, the mutex can protect the shared resources via exclusive access. In addition, the mutex can prevent semaphore priority inversion, which occurs when a low-priority task holds a semaphore but a high-priority task has to wait until the low-priority task releases it.

## Working Principles<a name="section115161649726"></a>

In a multi-task environment, multiple tasks may access the same shared resources. However, certain shared resources are not shared, and can only be accessed exclusively by tasks. A mutex can be used to address this issue.

When non-shared resources are accessed by a task, the mutex is locked. Other tasks will be blocked until the mutex is released by the task. The mutex allows only one task to access the shared resources at a time, ensuring integrity of operations on the shared resources.

**Figure  1**  Mutex working mechanism<a name="fig04871041163213"></a>  
![](figure/mutex-working-mechanism.png "mutex-working-mechanism")

