# Function Flow Runtime Serial Queue (C)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung-->
<!--Designer: @zhanglu161-->
<!--Tester: @lotsof-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=b74b00cc5805225620b940e38531d901e6362478 translatedAt=2026-08-15T01:49:21.048Z pushedAt=2026-08-15T07:42:44.734Z -->

## Overview

The FFRT serial queue is implemented based on the coroutine scheduling model. It provides efficient message queue functions and supports multiple service scenarios, such as asynchronous communication, traffic peak clipping, lock-free status and resource management, and architecture decoupling. The following functions are supported:

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

<!-- @[serial_c_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/FunctionFlowRuntime/SerialQueue/entry/src/main/cpp/serial_queue.h) -->

``` C
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "hilog/log.h"
#include "ffrt/ffrt.h" // From the OpenHarmony third-party library "@ppd/ffrt"
```

<!-- @[serial_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/FunctionFlowRuntime/SerialQueue/entry/src/main/cpp/serial_queue.cpp) -->

``` C++
#undef LOG_TAG
#define LOG_TAG "SerialTag"

typedef struct {
    FILE *logFile;          // Log file pointer.
    ffrt_queue_t queue;     // Task queue.
} LoggerT;

// Global Logger variable.
LoggerT* g_logger = nullptr;

// Initialize the logging system.
LoggerT *LoggerCreate(const char *filename)
{
    LoggerT *logger = (LoggerT *)malloc(sizeof(LoggerT));
    if (!logger) {
        OH_LOG_ERROR(LOG_APP, "Failed to allocate memory for LoggerT");
        return nullptr;
    }

    // Open the log file.
    logger->logFile = stdout;
    if (!logger->logFile) {
        OH_LOG_ERROR(LOG_APP, "Failed to open log file");
        free(logger);
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "Log file opened: %{public}s", filename);

    // Create the task queue.
    logger->queue = ffrt_queue_create(ffrt_queue_serial, "logger_queue_c", NULL);
    if (!logger->queue) {
        OH_LOG_ERROR(LOG_APP, "Failed to create queue");
        fclose(logger->logFile);
        free(logger);
        return nullptr;
    }

    return logger;
}

// Destroy the logging system.
void LoggerDestroy(LoggerT *logger)
{
    if (logger) {
        // Destroy the queue.
        if (logger->queue) {
            ffrt_queue_destroy(logger->queue);
        }

        // Close the log file.
        if (logger->logFile) {
            fclose(logger->logFile);
            OH_LOG_INFO(LOG_APP, "Log file closed");
        }

        free(logger);
    }
}

// Log task.
void WriteTask(void *arg)
{
    char *message = (char *)arg;
    if (g_logger && g_logger->logFile) {
        OH_LOG_INFO(LOG_APP, "Writing message %{public}s", message);
        fflush(g_logger->logFile);
    }

    free(message);
}

// Add a log task.
void LoggerLog(LoggerT *logger, const char *message)
{
    if (!logger || !logger->queue) {
        return;
    }

    // Copy the message string.
    char *messageCopy = strdup(message);
    if (!messageCopy) {
        OH_LOG_ERROR(LOG_APP, "Failed to allocate memory for message");
        return;
    }

    ffrt_queue_submit_f(logger->queue, WriteTask, messageCopy, NULL);
}

int SerialQueueCExec()
{
    // Initialize the global logger.
    g_logger = LoggerCreate("log_c.txt");
    if (!g_logger) {
        return -1;
    }

    // Add a log task using the global logger.
    LoggerLog(g_logger, "Log message 1");
    LoggerLog(g_logger, "Log message 2");
    LoggerLog(g_logger, "Log message 3");

    // Simulate the main thread continuing to execute other tasks.
    sleep(1);

    // Destroy the global logger.
    LoggerDestroy(g_logger);
    g_logger = nullptr;
    return 0;
}
```

> **NOTE**
>
> The `ffrt_queue_submit_h_f` API can receive a naked function pointer task as a parameter. If there are pre-processing and post-processing operations on the task, refer to the [ffrt_alloc_auto_managed_function_storage_base](ffrt-api-guideline-c.md#ffrt_alloc_auto_managed_function_storage_base) function to construct the task structure.

## Available APIs

The main FFRT APIs involved in the preceding sample are as follows. For details, see the methods under [ffrt_queue_t](ffrt-api-guideline-c.md#ffrt_queue_t):

| Name                                                       | Description                                                                 |
| ----------------------------------------------------------- | --------------------------------------------------------------------- |
| ffrt_queue_create   | Creates a queue.                                                            |
| ffrt_queue_destroy  | Destroys a queue.                                                            |
| ffrt_queue_submit_f | Submits a task to the queue.<br/>**Note:** This API is supported since API version 20. |

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify header file inclusion, that is, use the `#include "ffrt/ffrt.h"` header file inclusion statement.

## Constraints

- **Avoid submitting ultra-long tasks.** The FFRT has a built-in process-level queue task timeout detection mechanism. When the execution time of a serial task exceeds the preset threshold (30 seconds by default), the system prints and reports exception logs and triggers the preset process timeout callback function (if configured).

- **Use synchronization primitives correctly.** Do not use `std::mutex`, `std::condition_variable`, or `std::recursive_mutex` in the task closure submitted to FFRT. As synchronization primitives in the standard library will occupy the FFRT Worker thread for a long time, you should use the synchronization primitives provided by FFRT: `ffrt::mutex`, `ffrt::condition_variable`, or `ffrt::recursive_mutex`. The usage is the same as that of the standard library.

- **Manage queues in global variables.** If serial queues are managed in global variables and destroyed with service processes, pay attention to lifecycle decoupling in the test program. When the test is complete, the serial queue needs to be explicitly released. Other resources can be released with global variables. The reason is that global variables are destructed after the main function ends, and the release of serial queues depends on other resources in the FFRT framework, and the resources may have been destroyed.