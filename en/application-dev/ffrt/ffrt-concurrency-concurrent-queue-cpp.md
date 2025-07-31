# Function Flow Runtime Concurrent Queue (C++)

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

```cpp
#include <iostream>
#include <unistd.h>
#include "ffrt/ffrt.h" // From the OpenHarmony third-party library "@ppd/ffrt"

class BankQueueSystem {
private:
    std::unique_ptr<ffrt::queue> queue_;

public:
    BankQueueSystem(const char *name, int concurrency)
    {
        queue_ = std::make_unique<ffrt::queue>(
            ffrt::queue_concurrent, name, ffrt::queue_attr().max_concurrency(concurrency));
        std::cout << "bank system has been initialized" << std::endl;
    }

    ~BankQueueSystem()
    {
        queue_ = nullptr;
        std::cout << "bank system has been destroyed" << std::endl;
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
    usleep(100 * 1000);
    std::cout << "saving or withdraw ordinary customer" << std::endl;
}

void BankBusinessVIP()
{
    usleep(100 * 1000);
    std::cout << "saving or withdraw VIP" << std::endl;
}

int main()
{
    BankQueueSystem bankQueue("Bank", 2);

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
| class [task_attr](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#task_attr)   | Task attribute class.|
| class [queue_attr](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#queue_attr) | Queue attribute class.|
| class [queue](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#queue)           | Queue class.    |

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify the header file inclusion, that is, use the `#include "ffrt/ffrt.h"` header file to include statements.

## Constraints

1. It is recommended that the maximum concurrency of a concurrent queue be within a proper range. If the value is too large, it is meaningless to exceed the number of Worker threads. If the value is too small, the system resource utilization may be low.
