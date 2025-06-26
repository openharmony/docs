# Function Flow Runtime Serial Queue (C++)

## Overview

The FFRT serial queue is implemented based on the coroutine scheduling model. It provides efficient message queue functions and supports multiple service scenarios, such as asynchronous communication, mobile data peak clipping, lock-free status and resource management, and architecture decoupling. The following functions are supported:

- **Queue creation and destruction**: The queue name and priority can be specified during creation. Each queue is equivalent to an independent thread. Tasks in the queue are executed asynchronously compared with user threads.
- **Task delay**: The `delay` can be set when a task is submitted. The unit is `μs`. The delayed task will be scheduled and executed after `uptime` (submission time + delay time).
- **Serial scheduling**: Tasks in the same queue are sorted in ascending order of `uptime` and executed in serial mode. Ensure that the next task starts to be executed only after the previous task in the queue is complete.
- **Task canceling**: You can cancel a task that is not dequeued based on the task handle. The task cannot be canceled if it has been started or completed.
- **Task waiting**: You can wait for a task to complete based on the task handle. When a specified task is complete, all tasks whose `uptime` is earlier than the specified task in the queue have been executed.
- **Task priority**: You can set the priority of a single task when submitting the task. Priorities take effect only after a task is dequeued relative to other system loads, and do not affect the serial task order in the same queue. If the task priority is not set, the priority of the queue is inherited by default.

## Example: Asynchronous Log System

The following is an example of implementing an asynchronous log system. The main thread submits the log task to the queue, and the background thread obtains the task from the queue and writes the task to the file. It ensures the log sequence and prevents the main thread from being blocked by the file write operation.

With FFRT APIs, you only need to focus on service logic implementation and do not need to pay attention to asynchronous thread management, thread security, and scheduling efficiency.

The example simplifies the logic for handling exceptions and ensuring thread security. The code is as follows:

```cpp
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include "ffrt/ffrt.h"

class Logger {
public:
    Logger(const std::string& filename)
    {
        // Create a queue.
        queue_ = std::make_unique<ffrt::queue>("loggerQueue");

        // Open a file in append mode.
        logFile_.open(filename, std::ios::app);
        if (!logFile_.is_open()) {
            throw std::runtime_error("Failed to open log file: " + filename);
        }
        std::cout << "Log file opened: " << filename << std::endl;
    }

    ~Logger() {
        // Destroy the queue.
        queue_ = nullptr;

        if (logFile_.is_open()) {
            logFile_.close();
            std::cout << "Log file closed" << std::endl;
        }
    }

    // Add a log task.
    void log(const std::string& message) {
        queue_->submit([this, message] {
            logFile_ << message << std::endl;
        });
    }

private:
    std::ofstream logFile_;
    std::unique_ptr<ffrt::queue> queue_;
};

int main()
{
    Logger logger("log.txt");

    // The main thread adds the log task.
    logger.log("Log message 1");
    logger.log("Log message 2");
    logger.log("Log message 3");

    // Simulate the main thread to continue executing other tasks.
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}
```

## Available APIs

The main FFRT APIs involved in the preceding example are as follows:

| Name                                                                                                                 | Description          |
| --------------------------------------------------------------------------------------------------------------------- | -------------- |
| class [queue](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#queue)   | Queue class.      |
| [sleep_for](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#sleep_for) | Delays a task for some time.|

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify the header file inclusion, that is, use the `#include "ffrt/ffrt.h"` header file to include statements.

## Constraints

- **Avoid submitting ultra-long tasks.** The FFRT has a built-in process-level queue task timeout detection mechanism. When the execution time of a serial task exceeds the preset threshold (30 seconds by default), the system prints and reports exception logs and triggers the preset process timeout callback function (if configured).
- **Use synchronization primitives correctly.** Do not use `std::mutex`, `std::condition_variable`, or `std::recursive_mutex` in the task closure submitted to FFRT. As synchronization primitives in the standard library will occupy the FFRT Worker thread for a long time, you should use the synchronization primitives provided by FFRT: `ffrt::mutex`, `ffrt::condition_variable`, or `ffrt::recursive_mutex`. The usage is the same as that of the standard library.
- **Manage queues in global variables.** If serial queues are managed in global variables and destroyed with service processes, pay attention to lifecycle decoupling in the test program. When the test is complete, the serial queue needs to be explicitly released. Other resources can be released with global variables. The reason is that global variables are destructed after the main function ends, and the release of serial queues depends on other resources in the FFRT framework, and the resources may have been destroyed.
