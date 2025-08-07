# Function Flow Runtime Concurrent Queue (C)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The FFRT concurrent queue provides the capability of setting the priority and queue concurrency. Tasks in the queue can be executed on multiple threads at the same time, achieving better effects.

- **Queue concurrency**: You can set the maximum concurrency of a queue to control the number of tasks that can be executed at the same time. This avoids system resource impact caused by excessive concurrent tasks, ensuring system stability and performance.
- **Task priority**: You can set a priority for each task. Different tasks are scheduled and executed strictly based on the priority. Tasks with the same priority are executed in sequence. Tasks with higher priorities are executed prior to those with lower priorities to ensure that key tasks can be processed in a timely manner.

## Example: Bank Service System

For example, each customer (common customer or VIP customer) submits a service request to the bank service system. The service request of the VIP customer can be processed first.
The bank system has two windows for handling service requests submitted by customers. You can use the FFRT paradigm to perform the following modeling:

- **Queuing logic**: concurrent queue.
- **Service window**: concurrency of the concurrent queue, which also equals the number of FFRT Worker threads.
- **Customer level**: priority of concurrent queue tasks.

The implementation code is as follows:

```c
#include <stdio.h>
#include <unistd.h>
#include "ffrt/ffrt.h" // From the OpenHarmony third-party library "@ppd/ffrt"

ffrt_queue_t create_bank_system(const char *name, int concurrency)
{
    ffrt_queue_attr_t queue_attr;
    (void)ffrt_queue_attr_init(&queue_attr);
    ffrt_queue_attr_set_max_concurrency(&queue_attr, concurrency);

    // Create a concurrent queue.
    ffrt_queue_t queue = ffrt_queue_create(ffrt_queue_concurrent, name, &queue_attr);

    // Destroy the queue attributes after the queue is created.
    ffrt_queue_attr_destroy(&queue_attr);
    if (!queue) {
        printf("create queue failed\n");
        return NULL;
    }

    printf("create bank system successfully\n");
    return queue;
}

void destroy_bank_system(ffrt_queue_t queue_handle)
{
    ffrt_queue_destroy(queue_handle);
    printf("destroy bank system successfully\n");
}

void bank_business(void *arg)
{
    usleep(100 * 1000);
    const char *data = (const char *)arg;
    printf("saving or withdraw for %s\n", data);
}

// Encapsulate the operation of submitting a task to a queue into a function.
ffrt_task_handle_t commit_request(ffrt_queue_t bank, void (*func)(void *), const char *name,
    ffrt_queue_priority_t level, int delay)
{
    ffrt_task_attr_t task_attr;
    (void)ffrt_task_attr_init(&task_attr);
    ffrt_task_attr_set_name(&task_attr, name);
    ffrt_task_attr_set_queue_priority(&task_attr, level);
    ffrt_task_attr_set_delay(&task_attr, delay);

    return ffrt_queue_submit_h_f(bank, func, name, &task_attr);
}

// Encapsulate the operation of canceling a task in a queue into a function.
int cancel_request(ffrt_task_handle_t request)
{
    return ffrt_queue_cancel(request);
}

// Encapsulate the operation of waiting for a task in a queue into a function.
void wait_for_request(ffrt_task_handle_t task)
{
    ffrt_queue_wait(task);
}

int main()
{
    ffrt_queue_t bank = create_bank_system("Bank", 2);
    if (!bank) {
        printf("create bank system failed\n");
        return -1;
    }

    ffrt_task_handle_t task1 = commit_request(bank, bank_business, "customer1", ffrt_queue_priority_low, 0);
    ffrt_task_handle_t task2 = commit_request(bank, bank_business, "customer2", ffrt_queue_priority_low, 0);
    // VIP customers have the priority to enjoy services.
    ffrt_task_handle_t task3 = commit_request(bank, bank_business, "customer3 VIP", ffrt_queue_priority_high, 0);
    ffrt_task_handle_t task4 = commit_request(bank, bank_business, "customer4", ffrt_queue_priority_low, 0);
    ffrt_task_handle_t task5 = commit_request(bank, bank_business, "customer5", ffrt_queue_priority_low, 0);

    // Cancel the service for customer 4.
    cancel_request(task4);

    // Wait until all customer services are complete.
    wait_for_request(task5);
    destroy_bank_system(bank);

    ffrt_task_handle_destroy(task1);
    ffrt_task_handle_destroy(task2);
    ffrt_task_handle_destroy(task3);
    ffrt_task_handle_destroy(task4);
    ffrt_task_handle_destroy(task5);
    return 0;
}
```

## Available APIs

The main FFRT APIs involved in the preceding example are as follows:

| Name                                                                                              | Description                  |
| -------------------------------------------------------------------------------------------------- | ---------------------- |
| [ffrt_queue_create](ffrt-api-guideline-c.md#ffrt_queue_t)                                     | Creates a queue.            |
| [ffrt_queue_destroy](ffrt-api-guideline-c.md#ffrt_queue_t)                                   | Destroys a queue.            |
| [ffrt_task_attr_set_queue_priority](ffrt-api-guideline-c.md#ffrt_task_attr_t)     | Sets the priority of a task in a queue.  |
| [ffrt_queue_attr_set_max_concurrency](ffrt-api-guideline-c.md#ffrt_queue_attr_t) | Sets the concurrency of the concurrent queue.|
| [ffrt_queue_submit_h_f](ffrt-api-guideline-c.md#ffrt_queue_t)                             | Submits a task to a queue.  |

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify the header file inclusion, that is, use the `#include "ffrt/ffrt.h"` header file to include statements.

## Constraints

1. `ffrt_queue_attr_t` must be initialized by calling `ffrt_queue_attr_init` before the attribute is set or obtained. If `ffrt_queue_attr_t` is no longer used, `ffrt_queue_attr_destroy` needs to be explicitly called to release resources.
2. `ffrt_queue_t` must explicitly call `ffrt_queue_destroy` to release resources before the process exits.
3. It is recommended that the maximum concurrency of a concurrent queue be within a proper range. If the value is too large, it is meaningless to exceed the number of Worker threads. If the value is too small, the system resource utilization may be low.
