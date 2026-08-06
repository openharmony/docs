# Function Flow Runtime Concurrent Queue (C++)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung-->
<!--Designer: @zhanglu161-->
<!--Tester: @lotsof-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=246cbb87769d7ba2d4f71c6a8b417a57ec2cbfa6 translatedAt=2026-08-03T08:16:23.819Z pushedAt=2026-08-03T09:07:32.196Z -->

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

<!-- @[concurrent_cpp_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/FunctionFlowRuntime/ConcurrentQueue/entry/src/main/cpp/concurrent_queue_cpp.h) -->

``` C
#include <unistd.h>
#include "hilog/log.h"
#include "ffrt/ffrt.h" // From the OpenHarmony third-party library "@ppd/ffrt"

#undef LOG_TAG
#define LOG_TAG "ConcurrentCppTag"
```

<!-- @[concurrent_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/FunctionFlowRuntime/ConcurrentQueue/entry/src/main/cpp/concurrent_queue_cpp.cpp) -->

``` C++

const int SLEEP_TIME = 100 * 1000;
const int BANK_CONCURRENCY = 2;

class BankQueueSystem {
private:
    std::unique_ptr<ffrt::queue> queue_;

public:
    BankQueueSystem(const char *name, int concurrency)
    {
        queue_ = std::make_unique<ffrt::queue>(
            ffrt::queue_concurrent, name, ffrt::queue_attr().max_concurrency(concurrency));
        OH_LOG_INFO(LOG_APP, "bank system has been initialized");
    }

    ~BankQueueSystem()
    {
        queue_ = nullptr;
        OH_LOG_INFO(LOG_APP, "bank system has been destroyed");
    }

    // Start to queue, that is, submit queue tasks.
    ffrt::task_handle Enter(const std::function<void()>& func, const char *name, ffrt_queue_priority_t level, int delay)
    {
        return queue_->submit_h(func, ffrt::task_attr().name(name).priority(level).delay(delay));
    }

    // Exit the queue, that is, cancel queue tasks.
    int Exit(const ffrt::task_handle &t)
    {
        return queue_->cancel(t);
    }

    // Wait for tasks in the queue.
    void Wait(const ffrt::task_handle& handle)
    {
        queue_->wait(handle);
    }
};

void BankBusiness()
{
    usleep(SLEEP_TIME);
    OH_LOG_INFO(LOG_APP, "saving or withdraw ordinary customer");
}

void BankBusinessVIP()
{
    usleep(SLEEP_TIME);
    OH_LOG_INFO(LOG_APP, "saving or withdraw VIP");
}

int ConcurrentQueueCppExec()
{
    BankQueueSystem bankQueue("Bank", BANK_CONCURRENCY);

    auto task1 = bankQueue.Enter(BankBusiness, "customer1", ffrt_queue_priority_low, 0);
    auto task2 = bankQueue.Enter(BankBusiness, "customer2", ffrt_queue_priority_low, 0);
    // VIP customers have the priority to enjoy services.
    auto task3 = bankQueue.Enter(BankBusinessVIP, "customer3 vip", ffrt_queue_priority_high, 0);
    auto task4 = bankQueue.Enter(BankBusiness, "customer4", ffrt_queue_priority_low, 0);
    auto task5 = bankQueue.Enter(BankBusiness, "customer5", ffrt_queue_priority_low, 0);

    // Cancel the service for customer 4.
    bankQueue.Exit(task4);

    // Wait until all customer services are complete.
    bankQueue.Wait(task5);
    return 0;
}
```

## Available APIs

The main FFRT APIs involved in the preceding example are as follows:

| Name                                                                                                                         | Description        |
| ----------------------------------------------------------------------------------------------------------------------------- | ------------ |
| class [task_attr](https://gitcode.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#task_attr)   | Task attribute class.|
| class [queue_attr](https://gitcode.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#queue_attr) | Queue attribute class.|
| class [queue](https://gitcode.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#queue)           | Queue class.    |

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify header file inclusion, that is, use the `#include "ffrt/ffrt.h"` statement.

## Constraints

It is recommended that the maximum concurrency of a concurrent queue be within a proper range. If the value is too large, it is meaningless to exceed the number of Worker threads. If the value is too small, the system resource utilization may be low.