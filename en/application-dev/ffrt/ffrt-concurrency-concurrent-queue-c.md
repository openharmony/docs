# Function Flow Runtime Concurrent Queue (C)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung-->
<!--Designer: @zhanglu161-->
<!--Tester: @lotsof-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=246cbb87769d7ba2d4f71c6a8b417a57ec2cbfa6 translatedAt=2026-08-03T08:16:27.892Z pushedAt=2026-08-03T08:56:28.568Z -->

## Overview

The FFRT concurrent queue provides the capability of setting the priority and queue concurrency. Tasks in the queue can be executed on multiple threads at the same time, achieving better effects.

- **Queue concurrency**: You can set the maximum concurrency of a queue to control the number of tasks that can be executed at the same time. This avoids system resource impact caused by excessive concurrent tasks, ensuring system stability and performance.

- **Task priority**: You can set a priority for each task. Different tasks are scheduled and executed strictly based on the priority. Tasks with the same priority are executed in sequence. Tasks with higher priorities are executed prior to those with lower priorities to ensure that key tasks can be processed in a timely manner.

## Example: Bank Service System

For example, each customer (common customer or VIP customer) submits a service request to the bank service system. The service request of the VIP customer can be processed first. The bank system has two windows for handling service requests submitted by customers.

You can use the FFRT paradigm to perform the following modeling:

- **Queuing logic**: concurrent queue.

- **Service window**: concurrency of the concurrent queue, which also equals the number of FFRT Worker threads.

- **Customer level**: priority of concurrent queue tasks.

The implementation code is as follows:

<!-- @[concurrent_c_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/FunctionFlowRuntime/ConcurrentQueue/entry/src/main/cpp/concurrent_queue.h) -->

``` C
#include <cstdio>
#include <unistd.h>
#include "hilog/log.h"
#include "ffrt/ffrt.h" // From the OpenHarmony third-party library "@ppd/ffrt"

#undef LOG_TAG
#define LOG_TAG "ConcurrentTag"
```

<!-- @[concurrent_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/FunctionFlowRuntime/ConcurrentQueue/entry/src/main/cpp/concurrent_queue.cpp) -->

``` C++

const int SLEEP_TIME = 100 * 1000;
const int BANK_CONCURRENCY = 2;

ffrt_queue_t CreateBankSystem(const char *name, int concurrency)
{
    ffrt_queue_attr_t queue_attr;
    (void)ffrt_queue_attr_init(&queue_attr);
    ffrt_queue_attr_set_max_concurrency(&queue_attr, concurrency);

    // Create a concurrent queue.
    ffrt_queue_t queue = ffrt_queue_create(ffrt_queue_concurrent, name, &queue_attr);

    // Destroy the queue attributes after the queue is created.
    ffrt_queue_attr_destroy(&queue_attr);
    if (!queue) {
        OH_LOG_INFO(LOG_APP, "create queue failed");
        return NULL;
    }

    OH_LOG_INFO(LOG_APP, "create bank system successfully");
    return queue;
}

void DestroyBankSystem(ffrt_queue_t queue_handle)
{
    ffrt_queue_destroy(queue_handle);
    OH_LOG_INFO(LOG_APP, "destroy bank system successfully");
}

void BankBusiness(void *arg)
{
    usleep(SLEEP_TIME);
    const char *data = (const char *)arg;
    OH_LOG_INFO(LOG_APP, "saving or withdraw for %{public}s", data);
}

// Encapsulate the queue task submission function.
ffrt_task_handle_t CommitRequest(ffrt_queue_t bank, void (*func)(void *), const char *name,
    ffrt_queue_priority_t level, int delay)
{
    ffrt_task_attr_t task_attr;
    (void)ffrt_task_attr_init(&task_attr);
    ffrt_task_attr_set_name(&task_attr, name);
    ffrt_task_attr_set_queue_priority(&task_attr, level);
    ffrt_task_attr_set_delay(&task_attr, delay);

    return ffrt_queue_submit_h_f(bank, func, (void*)name, &task_attr);
}

// Encapsulate the queue task cancellation function.
int CancelRequest(ffrt_task_handle_t request)
{
    return ffrt_queue_cancel(request);
}

// Encapsulate the queue task waiting function.
void WaitForRequest(ffrt_task_handle_t task)
{
    ffrt_queue_wait(task);
}

int ConcurrentQueueCExec()
{
    ffrt_queue_t bank = CreateBankSystem("Bank", BANK_CONCURRENCY);
    if (!bank) {
        printf("create bank system failed\n");
        OH_LOG_INFO(LOG_APP, "create bank system failed");
        return -1;
    }

    ffrt_task_handle_t task1 = CommitRequest(bank, BankBusiness, "customer1", ffrt_queue_priority_low, 0);
    ffrt_task_handle_t task2 = CommitRequest(bank, BankBusiness, "customer2", ffrt_queue_priority_low, 0);
    // VIPs enjoy higher-priority service.
    ffrt_task_handle_t task3 = CommitRequest(bank, BankBusiness, "customer3 VIP", ffrt_queue_priority_high, 0);
    ffrt_task_handle_t task4 = CommitRequest(bank, BankBusiness, "customer4", ffrt_queue_priority_low, 0);
    ffrt_task_handle_t task5 = CommitRequest(bank, BankBusiness, "customer5", ffrt_queue_priority_low, 0);

    // Cancel the service for customer 4.
    CancelRequest(task4);

    // Wait for all customer services to complete.
    WaitForRequest(task5);
    DestroyBankSystem(bank);

    ffrt_task_handle_destroy(task1);
    ffrt_task_handle_destroy(task2);
    ffrt_task_handle_destroy(task3);
    ffrt_task_handle_destroy(task4);
    ffrt_task_handle_destroy(task5);
    return 0;
}
```

> **NOTE**
>
> The `ffrt_queue_submit_h_f` API can receive a raw function pointer task as a parameter. If there are pre-processing and post-processing operations on the task, refer to the [ffrt_alloc_auto_managed_function_storage_base](ffrt-api-guideline-c.md#ffrt_alloc_auto_managed_function_storage_base) function to construct the task structure.

## Available APIs

The main FFRT APIs involved in the preceding example are as follows:

| Name                                                                            | Description                                                                 |
| -------------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| [ffrt_queue_create](ffrt-api-guideline-c.md#ffrt_queue_t)                        | Creates a queue.                                                           |
| [ffrt_queue_destroy](ffrt-api-guideline-c.md#ffrt_queue_t)                       | Destroys a queue.                                                           |
| [ffrt_task_attr_set_queue_priority](ffrt-api-guideline-c.md#ffrt_task_attr_t)    | Sets the priority of a task in a queue.                                                 |
| [ffrt_queue_attr_set_max_concurrency](ffrt-api-guideline-c.md#ffrt_queue_attr_t) | Sets the concurrency of the concurrent queue.                                               |
| [ffrt_queue_submit_h_f](ffrt-api-guideline-c.md#ffrt_queue_t)                    | Submits a task to a queue.<br>**Note**: This API is supported since API version 20.|

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify header file inclusion, that is, use the `#include "ffrt/ffrt.h"` header file to include statements.

## Constraints

1. `ffrt_queue_attr_t` must be initialized by calling `ffrt_queue_attr_init` before the attribute is set or obtained. If `ffrt_queue_attr_t` is no longer used, `ffrt_queue_attr_destroy` needs to be explicitly called to release resources.

2. `ffrt_queue_t` must explicitly call `ffrt_queue_destroy` to release resources before the process exits.

3. It is recommended that the maximum concurrency of a concurrent queue be within a proper range. If the value is too large, it is meaningless to exceed the number of Worker threads. If the value is too small, the system resource utilization may be low.